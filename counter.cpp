#include "counter.h"

Calculator::Calculator(QObject *parent) : QObject(parent), text_content("0"), m_firstOperand(0),m_secondOperand(0), m_waitingForOperand(true) {}

QString Calculator::textContent() const {
    return text_content;
}

void Calculator::handleButton(const QString &buttonText) {
    if(buttonText == "="){
        m_secondOperand = text_content.toDouble();
        setTextContent("");
        m_waitingForOperand = true;
        if (m_operation == "+"){
            double otvet = m_firstOperand + m_secondOperand;
            setTextContent(QString::number(otvet));
        }
        else if (m_operation == "-"){
            double otvet = m_firstOperand - m_secondOperand;
            setTextContent(QString::number(otvet));
        }
        else if (m_operation == "*"){
            double otvet = m_firstOperand * m_secondOperand;
            setTextContent(QString::number(otvet));
        }
        else if (m_operation == "/"){
            double otvet = m_firstOperand / m_secondOperand;
            setTextContent(QString::number(otvet));
        }
    }else if (buttonText == "%") {
        // Вычисляем процент от текущего числа
        double value = text_content.toDouble(); // Получаем текущее число
        double percent = value / 100.0;        // Вычисляем процент
        setTextContent(QString::number(percent)); // Обновляем текст
    }else{
        m_operation = buttonText;
        if(m_waitingForOperand){
            m_firstOperand = text_content.toDouble();
            setTextContent("");
            m_waitingForOperand = false;
        }else{
            m_secondOperand = text_content.toDouble();
            setTextContent("");
            m_waitingForOperand = true;
        }
        if(m_waitingForOperand){
            if (m_operation == "+"){
                double otvet = m_firstOperand + m_secondOperand;
                setTextContent(QString::number(otvet));
            }
            else if (m_operation == "-"){
                double otvet = m_firstOperand -  m_secondOperand;
                setTextContent(QString::number(otvet));
            }
            else if (m_operation == "*"){
                double otvet = m_firstOperand * m_secondOperand;
                setTextContent(QString::number(otvet));
            }
            else if (m_operation == "/"){
                double otvet = m_firstOperand / m_secondOperand;
                setTextContent(QString::number(otvet));
            }
        }
    }
}

void Calculator::setTextContent(const QString &text) {
    if (text_content != text) {
        text_content = text;
        emit textContentChanged();
    }
}
