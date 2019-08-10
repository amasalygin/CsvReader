#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent) : QSortFilterProxyModel (parent)
{
    _filterText = "";
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(_filterText.isEmpty())
        return true;

    QModelIndex ind = sourceModel()->index(source_row,
                                                   0, source_parent);

    QString name = sourceModel()->data(ind, PersonModel::NameRole).toString();
    QString post = sourceModel()->data(ind, PersonModel::PostRole).toString();

    /// Регистро-независимое сравнение
    if(post.contains(_filterText, Qt::CaseInsensitive) || name.contains(_filterText, Qt::CaseInsensitive))
        return true;

    return false;
}

void ProxyModel::setFilterText(const QString &text)
{
    _filterText = text;
    invalidateFilter();
}

