#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class Register;
class login : public QDialog,public std::enable_shared_from_this<login>
        //允许这个类转化为智能指针，这个智能指针跟所有引用这个对象的智能指针共享引用计数
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    void initSignals();
    ~login();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    std::shared_ptr<Register> _register;
};
#endif // LOGIN_H
