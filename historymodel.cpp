#pragma once

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
        _historyModel = model;
        emit historyModelChanged();
    }
    
    DataModel* historyModel() const { return _historyModel; }
    
public slots:
    void handleButton();
    
signals:
    void textContentChanged();
    void historyModelChanged();
    
private:
    DataModel* _historyModel = nullptr;
    QString _textContent;
    bool _flag;
    
    void addHistoryEntry(const QString &stroka) {
        if (_historyModel) {
            _historyModel->addItem(stroka);
        }
    }
};
