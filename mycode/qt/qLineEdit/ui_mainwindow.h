/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *Ip_Edit;
    QLabel *Ip_Lable;
    QLineEdit *Email_Edit;
    QLineEdit *Pwd_Edit;
    QLabel *Pwd_Lable;
    QLabel *Email_Lable;
    QLabel *Mask_Lable;
    QLineEdit *Mask_Edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1084, 769);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 40, 921, 631));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        Ip_Edit = new QLineEdit(gridLayoutWidget);
        Ip_Edit->setObjectName(QString::fromUtf8("Ip_Edit"));

        gridLayout->addWidget(Ip_Edit, 2, 2, 1, 1);

        Ip_Lable = new QLabel(gridLayoutWidget);
        Ip_Lable->setObjectName(QString::fromUtf8("Ip_Lable"));

        gridLayout->addWidget(Ip_Lable, 2, 0, 1, 1);

        Email_Edit = new QLineEdit(gridLayoutWidget);
        Email_Edit->setObjectName(QString::fromUtf8("Email_Edit"));

        gridLayout->addWidget(Email_Edit, 0, 2, 1, 1);

        Pwd_Edit = new QLineEdit(gridLayoutWidget);
        Pwd_Edit->setObjectName(QString::fromUtf8("Pwd_Edit"));

        gridLayout->addWidget(Pwd_Edit, 1, 2, 1, 1);

        Pwd_Lable = new QLabel(gridLayoutWidget);
        Pwd_Lable->setObjectName(QString::fromUtf8("Pwd_Lable"));

        gridLayout->addWidget(Pwd_Lable, 1, 0, 1, 1);

        Email_Lable = new QLabel(gridLayoutWidget);
        Email_Lable->setObjectName(QString::fromUtf8("Email_Lable"));

        gridLayout->addWidget(Email_Lable, 0, 0, 1, 1);

        Mask_Lable = new QLabel(gridLayoutWidget);
        Mask_Lable->setObjectName(QString::fromUtf8("Mask_Lable"));

        gridLayout->addWidget(Mask_Lable, 3, 0, 1, 1);

        Mask_Edit = new QLineEdit(gridLayoutWidget);
        Mask_Edit->setObjectName(QString::fromUtf8("Mask_Edit"));

        gridLayout->addWidget(Mask_Edit, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1084, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Ip_Lable->setText(QCoreApplication::translate("MainWindow", "ip:", nullptr));
        Pwd_Lable->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201: ", nullptr));
        Email_Lable->setText(QCoreApplication::translate("MainWindow", "\351\202\256\347\256\261: ", nullptr));
        Mask_Lable->setText(QCoreApplication::translate("MainWindow", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
