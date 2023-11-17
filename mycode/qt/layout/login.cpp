#include "login.h"
#include "ui_login.h"
#include "register.h"
using namespace std;
login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

void login::initSignals()
{
    _register=make_shared<Register>();
   // _register->set_login(this);    this是一个裸指针，不能给weak_ptr赋值

   //_register->set_login(shared_ptr<Login>(this));
   //如果在外部再次创建一个智能指针来管理同一个对象，就会导致问题。这是因为两个不同的智能指针对象
   //在其生命周期结束时都会尝试释放相同的对象内存。这种情况下，当第一个智能指针的引用计数
   //减为零时，它会释放对象的内存。然而，此时外部的第二个智能指针仍然在使用对象，
   //因此当它试图释放相同的内存时，就会导致对象的二次析构，可能导致未定义的行为,解决方案是引用计数共享。

    _register->set_login(shared_from_this());
    //返回一个当前类的智能指针,前提是已经有一个智能指针对它做了管理
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_2_clicked()
{
    this->close();
    _register->show();
}
