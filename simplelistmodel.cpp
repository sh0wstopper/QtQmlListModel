#include "simplelistmodel.h"
#include "dataobject.h"

// You can define custom data roles starting with Qt::UserRole
const int SimpleListModel::FirstNameRole = Qt::UserRole + 1;
const int SimpleListModel::LastNameRole = Qt::UserRole + 2;

SimpleListModel::SimpleListModel(QObject *parent) :
    QAbstractListModel(parent) {
}

QHash<int, QByteArray> SimpleListModel::roleNames() const {
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(FirstNameRole, QByteArray("firstName"));
    roles.insert(LastNameRole, QByteArray("lastName"));
    return roles;
}

int SimpleListModel::rowCount(const QModelIndex &) const {
	return m_items.size();
}

QVariant SimpleListModel::data(const QModelIndex &index,
                                            int role) const {
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (m_items.size()-1) )
        return QVariant();

    DataObject *dobj = m_items.at(index.row());
    switch (role) {
    case Qt::DisplayRole: // The default display role now displays the first name as well
    case FirstNameRole:
        return QVariant::fromValue(dobj->first);
    case LastNameRole:
        return QVariant::fromValue(dobj->last);
    default:
        return QVariant();
    }
}

void SimpleListModel::addItem(DataObject *item)
{
    beginInsertRows(QModelIndex(), m_items.count(), m_items.count());
    m_items.append(item);
    endInsertRows();
}

DataObject* SimpleListModel::removeItem(int index)
{
    if(index<0 || index>=m_items.count()) return NULL;

    beginRemoveRows(QModelIndex(), index, index);
    DataObject* o = m_items.takeAt(index);
    endRemoveRows();
    return o;
}
