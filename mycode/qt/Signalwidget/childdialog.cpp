#include "childdialog.h"
#include "ui_childdialog.h"

ChildDialog::ChildDialog(QWidget *parent) :
    QDialog(parent),_parent(parent),
    ui(new Ui::ChildDialog)
{
    ui->setupUi(this);
    connect(ui->ShowMainWindow,&QPushButton::clicked,this,&ChildDialog::ShowMainWindow);
}

ChildDialog::~ChildDialog()
{
    delete ui;
}

void ChildDialog::ShowMainWindow()
{
    this->hide();
//    _parent->show();
    emit ShowMainSig();
}
