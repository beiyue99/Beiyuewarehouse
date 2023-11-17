#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<qtableview.h>
#include <QMainWindow>

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
    QTableView * _table_view;
    QTableView * _table_view2;
};
#endif // MAINWINDOW_H
