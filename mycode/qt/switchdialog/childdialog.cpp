#include "childdialog.h"
#include "ui_childdialog.h"
#include<QtDebug>
ChildDialog::ChildDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::on_EnterMainBtn_clicked()
{
    qDebug()<<tr("点击了主界面按钮")<<endl;
    accept();
    //accept()函数可以使对话框关闭，并且在调用exec()函数后返回QDialog::Accepted
}
