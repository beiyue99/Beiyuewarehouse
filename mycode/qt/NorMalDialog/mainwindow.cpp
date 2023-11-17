#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<QtDebug>
#include<QDir>
#include<QFileDialog>
#include<QInputDialog>
#include<QStringList>
#include<QMessageBox>
#include<QWizard>
#include<QHBoxLayout>
#include<QLabel>
#include<QRadioButton>
#include<QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ColorBtn_clicked()
{
    QColorDialog coldlg(Qt::blue,this);
    coldlg.setOption(QColorDialog::ShowAlphaChannel);
    coldlg.exec();
    QColor color=coldlg.currentColor();
    qDebug()<<"选择的颜色是："<<color<<endl;
}

//文本对话框需要打开一个文件
void MainWindow::on_pushButton_clicked()
{
    QString Path = QDir::currentPath();
    QString Title = tr("文件对话框");
    //如果你的应用程序需要支持多种语言，那么建议使用tr()函数来实现字符串的本地化
    QString Filter = tr("文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)");
    //打开文件的不同格式选项需要用;;分隔
    QString FileName=QFileDialog::getOpenFileName(this,Title,Path,Filter);
    qDebug()<<"打开的文件名"<<FileName<<endl;
}



void MainWindow::on_pushButton_3_clicked()
{
    bool ok =false;
    auto intdate=QInputDialog::getDouble(this,tr("数字输入对话框"),tr("请输入提示"),10.1,-2.0,80.4,2,&ok);
    if(ok)
    {
        qDebug()<<intdate<<endl;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    bool ok =false;
    auto intdate=QInputDialog::getInt(this,tr("数字输入对话框"),tr("请输入提示"),200,-200,400,10,&ok);
    if(ok)
    {
        qDebug()<<intdate<<endl;
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    QStringList item;
    item<<tr("条目1")<<tr("条目2");
    bool ok =false;
    auto Itemdate=QInputDialog::getItem(this,tr("条目对话框"),tr("输入或选择条目"),item,0,true,&ok);
    if(ok)
    {
        qDebug()<<"item is "<<Itemdate<<endl;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    auto ret=QMessageBox::question(this,tr("提示对话框"),tr("你是单身吗？"),QMessageBox::Yes,QMessageBox::No);
    if(ret==QMessageBox::Yes)
    {
        qDebug()<<"ret is "<<ret;
    }
    else {return;}

    auto ret2=QMessageBox::information(this,tr("通知对话框"),tr("你好单身狗"),
                                       QMessageBox::Yes,QMessageBox::No);
    if(ret2==QMessageBox::Yes)
    {
        qDebug()<<"ret2 is "<<ret2;
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    progressdlg = new QProgressDialog(tr("正在复制"),tr("取消复制"),0,5000,this);
    progressdlg->setWindowTitle(tr("文件复制进度对话框"));
    progressdlg->setWindowModality(Qt::ApplicationModal);
    timer=new QTimer(this);
    //计时器每走一次会触发超时事件，然后触发回调
    connect(timer,&QTimer::timeout,this,&MainWindow::on_updateProgressDialog);
    connect(progressdlg,&QProgressDialog::canceled,this,&MainWindow::on_cancelProgressDialog);
    timer->start(2);//每2ms触发一次
}

void MainWindow::on_updateProgressDialog()
{
    counter++;  //统计触发次数
    if(counter>5000)
    {
        timer->stop();
        delete timer;
        timer=nullptr;
        delete progressdlg;
        counter=0;
        return ;
    }
    progressdlg->setValue(counter);

}

void MainWindow::on_cancelProgressDialog()
{
    timer->stop();
    delete timer;
    timer=nullptr;
    delete progressdlg;
    progressdlg=nullptr;
    counter=0;
    return ;
}



void MainWindow::on_pushButton_7_clicked()
{
    QWizard wizard(this);
        wizard.setWindowTitle(tr("全城热恋"));
        QWizardPage* page1 = new QWizardPage();
        page1->setTitle(tr("婚恋介绍引导程序"));
        auto label1 = new QLabel();
        label1->setText(tr("该程序帮助您找到人生伴侣"));
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(label1);
        page1->setLayout(layout);
        wizard.addPage(page1);
        QWizardPage* page2 = new QWizardPage();
        page2->setTitle("选择心动类型");

        QButtonGroup *group = new QButtonGroup(page2);
        QRadioButton * btn1 = new QRadioButton();
        btn1->setText("白富美");
        group->addButton(btn1);
        QRadioButton * btn2 = new QRadioButton();
        btn2->setText("萝莉");
        group->addButton(btn2);
        QRadioButton * btn3 = new QRadioButton();
        btn3->setText("御姐");
        group->addButton(btn3);
        QRadioButton * btn4 = new QRadioButton();
        btn4->setText("小家碧玉");
        group->addButton(btn4);
        QRadioButton * btn5 = new QRadioButton();
        btn5->setText("女汉子");
        group->addButton(btn5);

        QRadioButton * btn6 = new QRadioButton();
        btn6->setText("成年人不做选择，全选!");
        group->addButton(btn6);
        QVBoxLayout *vboxLayout2 = new QVBoxLayout();
        for(int i = 0; i < group->buttons().size(); i++){
            vboxLayout2->addWidget(group->buttons()[i]);
        }

        page2->setLayout(vboxLayout2);
        wizard.addPage(page2);

        QWizardPage* page3 = new QWizardPage();
        page3->setTitle(tr("你的缘分即将到来"));
        auto label3 = new QLabel();
        label3->setText(tr("感谢您的参与，接下来的一个月会遇到对的人"));
        QVBoxLayout *layout3 = new QVBoxLayout();
        layout3->addWidget(label3);
        page3->setLayout(layout3);
        wizard.addPage(page3);
        wizard.show();
        wizard.exec();
}
