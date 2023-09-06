#include "subwindow.h"
#include "ui_subwindow.h"
#include<QtDebug>
SubWindow::SubWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
}

SubWindow::~SubWindow()
{
    qDebug()<<"我被吸够了...";
    delete ui;
}
