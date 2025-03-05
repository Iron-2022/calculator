#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QString>

class Calculator : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString textContent READ textContent WRITE setTextContent NOTIFY textContentChanged)
public:
    explicit Calculator(QObject *parent = nullptr);
    QString textContent() const;
    void setTextContent(const QString &text);
public slots:
    void handleButton(const QString &buttonText);
signals:
    void textContentChanged();
private:
    QString text_content;
    double m_firstOperand;
    double m_secondOperand;
    QString m_operation;
    bool m_waitingForOperand;
};

#endif
