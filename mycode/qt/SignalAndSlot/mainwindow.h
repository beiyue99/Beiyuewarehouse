#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "girlfriend.h"
#include "Me.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //添加hungry按钮的槽函数
    void hungryslot();
    void eatslot();

private:
    Ui::MainWindow *ui;
    Me* m_me;
    GirlFriend* m_girl;
};
#endif // MAINWINDOW_H
