#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_me=new Me;
    m_girl=new GirlFriend;
    void (GirlFriend::*girl1)()=&GirlFriend::hungry;
    void (GirlFriend::*girl2)(QString)=&GirlFriend::hungry;
    void (Me::*MyPoint)(QString)=&Me::eat;

    //connect(m_girl,&GirlFriend::hungry,m_me,&Me::eat);
    // connect(m_girl,&GirlFriend::hungry,this,&MainWindow::eatslot);
    //改写函数指针
    connect(m_girl,girl2,m_me,MyPoint);
    connect(m_girl,girl2,this,&MainWindow::eatslot);



     //信号连接槽函数
     //connect(ui->hungry,&QPushButton::clicked,this,&MainWindow::hungryslot);
    connect(ui->hungry,&QPushButton::clicked,this,[=]()
    {
        emit m_girl->hungry();
        emit m_girl->hungry("螺蛳粉");
    });





    //信号连接信号
     //connect(ui->hungry,&QPushButton::clicked,m_girl,&GirlFriend::hungry);


     //用qt4的方式进行连接
     //connect(m_girl,SIGNAL(hungry()),m_me,SLOT(eat()));
     //connect(m_girl,SIGNAL(hungry(QString)),m_me,SLOT(eat(QString)));






    connect(ui->cbt,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hungryslot()
{
    //发射自定义信号
    emit m_girl->hungry();
    emit m_girl->hungry("螺蛳粉");
}

void MainWindow::eatslot()
{
    qDebug()<<"我带你去吃海鲜...";
}

