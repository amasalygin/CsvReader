#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "person.h"

/**
 * @brief The PersonModel class - класс реализующий модель для ListView
 * В конструкторе... считывает csv-файл, заполняет _listItems
 */
class PersonModel : public QAbstractListModel
{
    Q_OBJECT

public:
    /**
     * @brief The Roles enum - для доступа к полям Person
     */
    enum Roles{
        NameRole = Qt::UserRole + 1,
        PostRole = 2,
    };
    explicit PersonModel( QObject *parent = nullptr);

    /** переопределенные методы от QAbstractListModel
     * @brief data
     * @brief rowCount
     * @brief roleNames
     */

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

private:
    /**
     * @brief _listItems - список объектов
     */
    QList<Person *> _listItems;
};

#endif // TABLEMODEL_H
