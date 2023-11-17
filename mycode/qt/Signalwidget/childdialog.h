#ifndef CHILDDIALOG_H
#define CHILDDIALOG_H

#include <QDialog>

namespace Ui {
class ChildDialog;
}

class ChildDialog : public QDialog
{
    Q_OBJECT
signals:
    void ShowMainSig();
public:
    explicit ChildDialog(QWidget *parent = nullptr);
    ~ChildDialog();
public slots:
    void ShowMainWindow();
private:
    Ui::ChildDialog *ui;
    QWidget * _parent;
};

#endif // CHILDDIALOG_H
