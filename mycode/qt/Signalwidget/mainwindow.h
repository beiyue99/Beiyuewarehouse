#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"childdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ChildDialog * _child_dialog;
public slots:
    void ShowChildDialog();
    void ShowMainDialog();
};
#endif // MAINWINDOW_H
