#include "maindialog.h"
#include<QDebug>
#include <QApplication>
#include"childdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//创建了一个 QApplication 对象 a，以管理应用程序的主事件循环
    MainDialog w;
    ChildDialog childlg;
    auto res =childlg.exec();
   if(res==QDialog::Accepted)
   {
       //exec() 方法会返回一个整数值，该值可以是 QDialog::Accepted 或 QDialog::Rejected
       //当用户在对话框中执行了确认操作，或者对话框执行了与接受相关的操作时，exec() 方法会返回 QDialog::Accepted
       qDebug()<<"child dialog exec returned,res is"<<res<<endl;
       w.show();
       a.exec();
       //a.exec() 会开始主事件循环，处理用户的输入和其他事件，直到所有窗口关闭并且应用程序退出
   }
   else
   {
       qDebug()<<"child dialog is exit,res is"<<res<<endl;
       return 0;
   }
//    w.show();
//    return a.exec();
}
