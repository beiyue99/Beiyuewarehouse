#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_moveBtn_clicked();

    void on_getBtn_clicked();

    void on_modifyBtn_clicked();

    void on_modifyBtn_2_clicked();

    void on_modelDlg_clicked();

    void on_msgBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
