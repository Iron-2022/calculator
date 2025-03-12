#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QString>
#include "historymodel.h"

class Calculator : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString textContent READ textContent WRITE setTextContent NOTIFY textContentChanged)
    Q_PROPERTY(DataModel* historyModel READ historyModel WRITE setHistoryModel NOTIFY historyModelChanged)
public:
    explicit Calculator(QObject *parent = nullptr);
    QString textContent() const;
    void setTextContent(const QString &text);


    void setHistoryModel(DataModel* model) {
        m_historyModel = model;
        emit historyModelChanged();
    }

    DataModel* historyModel() const { return m_historyModel; }

public slots:
    void handleButton();
signals:
    void textContentChanged();
    void historyModelChanged();
    void click_dot();
private:
    DataModel* m_historyModel = nullptr;
    QString text_content;
    bool flag;
    void addHistoryEntry(const QString &stroka) {
        if(m_historyModel) {
            m_historyModel->addItem(stroka);
        }
    }
};

#endif
