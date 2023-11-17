#ifndef REGISTER_H
#define REGISTER_H
#include<memory>
#include <QDialog>
using namespace std;
class login;
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    void set_login(const weak_ptr<login> &_login);
    void slot_register();
    ~Register();

private:
    Ui::Register *ui;
    std::weak_ptr<login> _login;
};

#endif // REGISTER_H
