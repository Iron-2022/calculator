#include "historymodel.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

#include "historymodel.h"

DataModel::DataModel(QObject *parent)
    : QAbstractListModel(parent)
{
    if (initializeDatabase()) {
        loadDataFromDatabase();
    }
}

bool DataModel::initializeDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("calculator_operations.db");

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS operations (id INTEGER PRIMARY KEY AUTOINCREMENT, operation TEXT)"))
        return false;

    return true;
}

void DataModel::loadDataFromDatabase()
{
    QSqlQuery query;
    if (!query.exec("SELECT operation FROM operations ORDER BY id ASC"))
        return;

    beginResetModel();
    _data.clear();

    while (query.next()) {
        QString operation = query.value(0).toString();
        _data.append(operation);
    }
    endResetModel();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _data.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= _data.size())
        return QVariant();

    if (role == DataRole)
        return _data.at(index.row());

    return QVariant();
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DataRole] = "itemData";
    return roles;
}

void DataModel::addItem(const QVariant &item)
{
    QSqlQuery query;

    if (rowCount() >= 256) {
        QSqlQuery deleteQuery;
        deleteQuery.exec("DELETE FROM operations WHERE id = (SELECT MIN(id) FROM operations)");
        beginRemoveRows(QModelIndex(), 0, 0);
        _data.removeFirst();
        endRemoveRows();
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO operations (operation) VALUES (:operation)");
    insertQuery.bindValue(":operation", item.toString());
    if (!insertQuery.exec())
        return;

    _data.append(item.toString());
}

QVariant DataModel::get(int index) const
{
    if (index >= 0 && index < _data.size())
        return _data.at(index);

    return QVariant();
}

void DataModel::clear()
{
    beginResetModel();
    _data.clear();
    endResetModel();
}
