#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRegExpValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString ip_mask="000.000.000.000;";
    // QString ip_mask="000.000.000.000;_";
    ui->Ip_Edit->setInputMask(ip_mask);
//    QString mac_mask="HH:HH:HH:HH:HH:HH;_";
    QString mac_mask="HH:HH:HH:HH:HH:HH;";
    ui->Mask_Edit->setInputMask(mac_mask);
    ui->Pwd_Edit->setEchoMode(QLineEdit::Password);
//    QRegExp regx("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+");
    QRegExp regx("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+");
    QValidator* validator=new QRegExpValidator(regx,ui->Email_Edit);
    ui->Email_Edit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

