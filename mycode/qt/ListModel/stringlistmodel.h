#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H
#include <QAbstractListModel>
#include <QStringList>
#include <QObject>
#include <QMimeData>
#include <QDataStream>

class StringListModel:public QAbstractListModel
{
    Q_OBJECT
public:
    StringListModel(const QStringList & strings, QObject* parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    Qt::ItemFlags  flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index,
                 const QVariant &value, int role = Qt::EditRole);

    bool insertRows(int position, int rows, const QModelIndex & index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex & index = QModelIndex());

    //编写拖动逻辑
    virtual QStringList mimeTypes() const;
    virtual QMimeData *mimeData(const QModelIndexList &indexes) const;
    virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                              int row, int column, const QModelIndex &parent);
    virtual Qt::DropActions supportedDropActions() const;
private:
    QStringList stringList;
};

#endif // STRINGLISTMODEL_H
