#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"mydialog.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口最大尺寸
    setMaximumSize(600,600);
    //设置窗口最小尺寸
    setMinimumSize(300,300);
    //设置窗口固定尺寸
    //setFixedSize(500,500);
    //设置窗口标题
    setWindowTitle("hello Qt");
    //给显示的窗口设置图标
   setWindowIcon(QIcon("d:\\图片\\liuxing.png"));

   connect(this,&MainWindow::windowTitleChanged,this,[=](const QString &title)
   {
       qDebug()<<"新的标题"<<title;
   });
   connect(this,&MainWindow::windowIconChanged,this,[=](const QIcon &icon)
   {
       qDebug()<<"图标被更换了...";
   });
   setContextMenuPolicy(Qt::CustomContextMenu);
   connect(this,&MainWindow::customContextMenuRequested,this,[=](const QPoint &pos)
   {
       QMenu menu;
       menu.addAction("西红柿");
       menu.addAction("土豆");
       menu.addAction("罗布");
       menu.exec(QCursor::pos());
   });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_moveBtn_clicked()
{
    QRect rect  =  this->frameGeometry();
    move(rect.topLeft()+QPoint(10,20));
}

void MainWindow::on_getBtn_clicked()
{
    QRect rect= this->frameGeometry();
    qDebug()<<"左上角:"<<rect.topLeft()
    <<"右上角:"<<rect.topRight()
    <<"左下角:"<<rect.bottomLeft()
    <<"右下角:"<<rect.bottomRight()
    <<"宽度:"<<rect.width()
    <<"高度:"<<rect.height();
}

void MainWindow::on_modifyBtn_clicked()
{
    int x=100+rand()%500;
    int y = 100+rand()%500;
    int width=this->width()+10;
    int height =this->height()+10;
    setGeometry(x,y,width,height);
}

void MainWindow::on_modifyBtn_2_clicked()
{
    setWindowTitle("你好,世界");
    setWindowIcon(QIcon("D:\\图片\\蔡文姬.jpg"));
}

void MainWindow::on_modelDlg_clicked()
{
    MyDialog dlg;
    connect(&dlg,&MyDialog::finished,this,[=](int res)
    {
    qDebug()<<"result:"<<res;
    });
    connect(&dlg,&MyDialog::accepted,this,[=]()
    {
    qDebug()<<"accepted信号被发射了...";
    });
    connect(&dlg,&MyDialog::rejected,this,[=]()
    {
    qDebug()<<"rejected信号被发射了.·.";
    });
    int ret = dlg.exec();   //显示对话框
    if(ret ==QDialog::Accepted)
    {
      qDebug()<<"accept button clicked...";
    }
    else if(ret==QDialog::Rejected)
    {
      qDebug()<<"reject button clicked...";
    }
    else
      qDebug()<<"done button clicked...";
}

void MainWindow::on_msgBtn_clicked()
{
   QMessageBox::about(this,"about","这是一个简单的消息提示框!!");
   QMessageBox::critical(this,"critical","这是一个错误对话框-critical..");
   int ret=QMessageBox::question(this,"guestion","你要保存修改的文件内容吗??",
   QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel);//默认为Cancel
   if(ret==QMessageBox::Save)
     QMessageBox::information(this,"information","恭喜你保存成功了,o(**)o!!!");
   else if(ret==QMessageBox::Cancel)
   {
     QMessageBox::warning(this,"warning","你放弃了保存,TTTT!!");
   }
}
