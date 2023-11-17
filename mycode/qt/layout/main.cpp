#include "login.h"
#include"register.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<login> w =make_shared<login>();
    w->initSignals();
    w->show();
    return a.exec();
}
