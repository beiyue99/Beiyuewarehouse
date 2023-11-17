#include "maindialog.h"
#include "ui_maindialog.h"
#include "childdialog.h"
MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}


void MainDialog::on_EnterChildBtn_clicked()
{
    close();
    //close函数不会直接销毁对象，而是将其标记为关闭状态，直到事件循环结束(当所有窗口都不显示)后才会被销毁
    ChildDialog childdialog;
    if(childdialog.exec()==QDialog::Accepted)
    {
        this->show();
    }
    else
    {
        return ;
    }
}
