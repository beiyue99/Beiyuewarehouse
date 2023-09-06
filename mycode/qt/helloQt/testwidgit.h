#ifndef TESTWIDGIT_H
#define TESTWIDGIT_H

#include <QWidget>

namespace Ui {
class TestWidgit;
}

class TestWidgit : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidgit(QWidget *parent = nullptr);
    ~TestWidgit();

private:
    Ui::TestWidgit *ui;
};

#endif // TESTWIDGIT_H
