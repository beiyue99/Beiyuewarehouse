#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QTableView>
#include "spinboxdelegate.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *model=new QStandardItemModel(7,4,this);
    for(int row=0;row<7;row++)
    {
        for(int column=0;column<4;column++)
        {
            QStandardItem* item=new QStandardItem(QString("%1").arg(row*4+column));
            model->setItem(row,column,item);
        }
    }
    _table_view =new QTableView;
    //QTableView是Qt框架中提供的一个用于显示表格数据的小部件类
    _table_view->setModel(model);
    setCentralWidget(_table_view);
    //setCentralWidget函数并传递一个QWidget或其子类的实例作为参数，
    //您可以将自定义的小部件或布局设置为主窗口的中心部件，使其成为主窗口的核心内容区域。
    this->resize(800,800);




    auto *model2=new QStandardItemModel(7,4,this);
    for(int row=0;row<7;row++)
    {
        for(int column=0;column<4;column++)
        {
            QStandardItem* item=new QStandardItem(QString("%1").arg(row*4+column));
            model2->setItem(row,column,item);
        }
    }
    auto * delegate=new SpinboxDelegate(this);
    _table_view2 =new QTableView();
    _table_view2->setModel(model2);
    _table_view2->setItemDelegate(delegate);  //设置自己的代理
    _table_view2->show();
    _table_view2->resize(800,800);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete _table_view;
    delete _table_view2;
}

