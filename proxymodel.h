#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

#include "personmodel.h"

/**
 * @brief The ProxyModel class - обертка поверх PersonModel для реализации фильтра
 */
class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit ProxyModel(QObject* parent = nullptr);
    bool filterAcceptsRow(int source_row,
                          const QModelIndex &source_parent) const;

public slots:
    /**
     * @brief  setFilterText(const QString &text) - этим методом задаем строку из QML
     */
    Q_INVOKABLE void setFilterText(const QString &text);
private:
    QString _filterText;
};
#endif // PROXYMODEL_H
