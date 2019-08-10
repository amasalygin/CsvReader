#include "personmodel.h"

#include <QDebug>
#include <QFile>

PersonModel::PersonModel(QObject *parent) : QAbstractListModel(parent)
{
    QFile f(":/test.csv");

    if(f.open(QIODevice::ReadOnly))
    {
        while (!f.atEnd()) {
            QList<QByteArray> values = f.readLine().split(';');
            if(values.count() >= 2)
                _listItems.append( new Person(values.at(0), values.at(1)));
        }
    }
    else
        qDebug()<< QString("Cannot open %1 - %2").arg(f.fileName()).arg(f.errorString());
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[PostRole] = "post";

    return roles;
}


int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _listItems.length();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _listItems.length())
        return QVariant();

    switch (role) {
    case NameRole:
        return _listItems.at(index.row())->getName();

    case PostRole:
        return _listItems.at(index.row())->getPost();

    default:
        return QVariant();
    }

}

