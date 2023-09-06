#include "testwidgit.h"
#include "ui_testwidgit.h"

TestWidgit::TestWidgit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidgit)
{
    ui->setupUi(this);
}

TestWidgit::~TestWidgit()
{
    delete ui;
}
