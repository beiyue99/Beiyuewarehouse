#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdialog.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qt4连接信号和槽函数
    //connect(ui->ShowChildButton,SIGNAL(clicked(bool)),this,SLOT(ShowChildDialog()));
    //ShowChildDialog()不得大于点击事件的参数，另外qt4的singal函数只是宏转换，因此不安全
    //推荐qt5的风格，免去了参数不匹配的麻烦，也免去了编译错误检测不到的麻烦
    connect(ui->ShowChildButton,&QPushButton::clicked,this,&MainWindow::ShowChildDialog);
    _child_dialog=new ChildDialog(this);
    // connect(_child_dialog,&ChildDialog::ShowMainSig,this,&MainWindow::ShowMainDialog);
    //用lambd表达式
    connect(_child_dialog,&ChildDialog::ShowMainSig,this,[this]()
    {
        this->_child_dialog->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _child_dialog;
    _child_dialog=nullptr;
}

void MainWindow::ShowChildDialog()
{
//    auto *ChildDialog=new QDialog(this);
//    ChildDialog->show();
    _child_dialog->show();
    this->hide();
}

void MainWindow::ShowMainDialog()
{
    this->show();
    _child_dialog->hide();
}

