#include "myaction.h"
#include<QLabel>
#include<QSplitter>

MyAction::MyAction(QObject *parent):QWidgetAction(parent)
{
    lineEdit=new QLineEdit();
    //连接信号跟槽，触发信号和发送文本的槽函数关联
    connect(lineEdit,&QLineEdit::returnPressed,this,&MyAction::sendText);


}

//myaction加到菜单项会调用这个函数
QWidget* MyAction::createWidget(QWidget * parent){
    if(parent->inherits("QMenu")|| parent->inherits("QToolBar")){
        QSplitter * spliter = new QSplitter(parent);
        QLabel * label = new QLabel;
        label->setText(tr("插入文本:"));
        spliter->addWidget(label);
        spliter->addWidget(lineEdit);
        return spliter;
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lineEdit->text());  //发送getText信号
    lineEdit->clear();
}
