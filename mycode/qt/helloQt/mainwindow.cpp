#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testwidgit.h"
#include "testdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在qt的构造函数中初始化（窗口，数据...）
    //显示当前窗口的时候，显示另外一个窗口 TestWidget
#if 0
    //创建窗口对象，没有给w对象指定副对象,这个窗口是一个独立窗口
    //要显示这个独蚀立窗口必须要进行show()操作
    TestWidgit* w=new TestWidgit;
    w->show();
#else
    //创建窗口对象，没有给w对象指定副对象
     // explicit TestWidgit(QWidget *parent = nullptr);
    //如果创建一个窗口对象的时候给其指定了父对象,就不是一个独立窗口
    //这样的话当前父窗口显示出来的时候，子窗口也会显示，这时候子窗口就没有边框
    TestWidgit* w=new TestWidgit(this);
#endif

#if 0
    //创建对话窗口
    TestDialog* dlg = new TestDialog(this);
    //非模态
    dlg->show();
#else
    //创建对话窗口
    TestDialog* dlg = new TestDialog(this);
    //模态,exec()
    //阻塞程序的执行 主窗口不会显示  也不能允许窗口间切换 当子窗口关闭，才会显示主窗口
    dlg->exec();
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

