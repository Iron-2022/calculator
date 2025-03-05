    #include "historymodel.h"

    DataModel::DataModel(QObject *parent)
        : QAbstractListModel(parent)
    {
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

    // Добавление элемента в модель
    void DataModel::addItem(const QVariant &item)
    {
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
