#include "spinboxdelegate.h"
#include<QSpinBox>
SpinboxDelegate::SpinboxDelegate(QObject* parent):QItemDelegate(parent)
{

}

QWidget *SpinboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox * editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void SpinboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    auto Spinbox = static_cast<QSpinBox*>(editor);
    Spinbox->setValue(value);
}

void SpinboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    //interpretText 是 QSpinBox 类的一个公共成员函数，用于将当前文本解释为一个整数，并将结果设置为旋转框的值
    int value = spinBox->value();
    model->setData(index,value,Qt::EditRole);
}

void SpinboxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
