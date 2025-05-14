#pragma once

#include <QAbstractListModel>
#include <QList>
#include <QVariant>

class DataModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DataModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addItem(const QVariant &item);
    QVariant get(int index) const;
    void clear();

private:
    bool initializeDatabase();
    void loadDataFromDatabase();

private:
    QVector<QString> _data;
};
