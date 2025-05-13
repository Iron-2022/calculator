#include "historymodel.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

DataModel::DataModel(QObject *parent)
    : QAbstractListModel(parent)
{
    if (initializeDatabase()) {
        loadDataFromDatabase(); // Загружаем данные после инициализации базы
    }
}

bool DataModel::initializeDatabase()
{
    // Установите соединение с базой данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("calculator_operations.db");

    if (!db.open()) {
        std::cout << "Не удалось открыть базу данных:" << std::endl;
        return false;
    }

    // Создание таблицы, если она не существует
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS operations (id INTEGER PRIMARY KEY AUTOINCREMENT, operation TEXT)")) {
        std::cout << "Не удалось создать таблицу:" << std::endl;
        return false;
    }

    return true;
}

void DataModel::loadDataFromDatabase()
{
    QSqlQuery query;
    // Выбираем все операции, отсортированные по id (по порядку добавления)
    if (!query.exec("SELECT operation FROM operations ORDER BY id ASC")) {
        std::cout << "Ошибка при чтении из базы: " << query.lastError().text().toStdString() << std::endl;
        return;
    }

    beginResetModel();
    m_data.clear();

    while (query.next()) {
        QString operation = query.value(0).toString();
        m_data.append(operation);
    }
    endResetModel();
}

// Количество элементов в модели
int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

// Получение данных по индексу и роли
QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_data.size())
        return QVariant();

    if (role == DataRole)
        return m_data.at(index.row());

    return QVariant();
}

// Имена ролей для QML
QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[DataRole] = "itemData";
    return roles;
}

// Добавление элемента в модель и в базу данных
void DataModel::addItem(const QVariant &item)
{
    // Сохранение операции в базе данных
    QSqlQuery query;
    query.prepare("INSERT INTO operations (operation) VALUES (:operation)");
    query.bindValue(":operation", item.toString());

    if (!query.exec()) {
        std::cout << "Не удалось сохранить операцию в базе данных: " << query.lastError().text().toStdString() << std::endl;
        return;
    }

    // Добавление элемента в модель
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(item);
    endInsertRows();
}

// Получение элемента по индексу
QVariant DataModel::get(int index) const
{
    if (index >= 0 && index < m_data.size())
        return m_data.at(index);

    return QVariant();
}

// Очистка модели
void DataModel::clear()
{
    beginResetModel();
    m_data.clear();
    endResetModel();
}
