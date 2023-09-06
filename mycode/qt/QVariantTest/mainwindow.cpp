#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int value=dataPlus(10,20).toUInt();
    QString str=dataPlus("hello","world").toString();
    qDebug()<<"int value:"<<value;
    qDebug()<<"string value:"<<str;

    Person p;
    p.id=250;
    p.name="张山峰";
#if 0
    QVariant v;
    v.setValue(p);
#else
    QVariant v = QVariant::fromValue(p);
#endif
    //取出V对象中的数据
    if(v.canConvert<Person>())
    {
    Person tmp =v.value<Person>();
    qDebug()<<"id:"<<tmp.id <<"name:"<<tmp.name;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVariant MainWindow::dataPlus(QVariant a, QVariant b)
{
    QVariant ret;
    //判断当前参数的类型是字符串还是整形数
    if(a.type()==QVariant::Int &&b.type()==QVariant::Int)
    {
    ret =QVariant(a.toInt()+b.toInt());
    }
    else if(a.type()==QVariant::String &&b.type()==QVariant::String)
    {
    ret.setValue(a.toString()+b.toString());
    }
    return ret;
}

