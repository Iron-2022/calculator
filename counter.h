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
    void handleButton(const QString &buttonText);
signals:
    void textContentChanged();
    void historyModelChanged();
private:
    DataModel* m_historyModel = nullptr;
    QString text_content;
    double m_firstOperand;
    double m_secondOperand;
    QString m_operation;
    bool m_waitingForOperand;
    void addHistoryEntry(double first, const QString& op, double second, double result) {
        if(m_historyModel) {
            QString entry = QString("%1 %2 %3 = %4").arg(first).arg(op).arg(second).arg(result);
            m_historyModel->addItem(entry);
        }
    }
};

#endif
