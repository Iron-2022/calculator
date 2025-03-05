#include <QAbstractListModel>
#include <QList>
#include <QVariant>

class DataModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DataModel(QObject *parent = nullptr);

    // Обязательные методы QAbstractListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // Методы для работы с данными
    Q_INVOKABLE void addItem(const QVariant &item);
    Q_INVOKABLE QVariant get(int index) const;
    Q_INVOKABLE void clear();

private:
    QList<QVariant> m_data;
    enum Roles {
        DataRole = Qt::UserRole + 1
    };
};
