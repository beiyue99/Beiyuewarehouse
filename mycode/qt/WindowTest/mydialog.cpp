#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_acceptBtn_clicked() //解除阻塞，隐藏窗口 返回1
{
    this->accept();
}

void MyDialog::on_rejectBtn_clicked() //解除阻塞，隐藏窗口 返回0
{
    this->reject();
}

void MyDialog::on_doneBtn_clicked()  //关闭窗口
{
    this->done(10);
}
