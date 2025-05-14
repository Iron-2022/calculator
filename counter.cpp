#include "counter.h"
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <clocale>

bool symbolicCorrectness(const std::string& str) {
    return (str != "e" && str != "+" && str != "-" && str != "*" && str != "/");
}

double evaluateExpression(const std::string& expression) {
    std::setlocale(LC_NUMERIC, "C");
    std::istringstream stream(expression);
    std::vector<double> values;
    std::vector<char> operators;

    double num;
    char op;
    std::string str;

    // Читаем первое число
    stream >> str;
    if (symbolicCorrectness(str))
        values.push_back(std::stod(str));
    else
        throw std::runtime_error("Некорректный формат выражения");

    while (stream >> op) {
        // Читаем следующее число
        stream >> str;
        if (symbolicCorrectness(str))
            num = std::stod(str);
        else
            throw std::runtime_error("Некорректный формат выражения");
        operators.push_back(op);
        values.push_back(num);
    }

    // Обрабатываем операторы в порядке их приоритета
    for (size_t i = 0; i < operators.size(); ++i) {
        char currentOp = operators[i];
        if (currentOp == '*' || currentOp == '/') {
            double left = values[i];
            double right = values[i + 1];
            if (currentOp == '/' && right == 0)
                throw std::runtime_error("Деление на ноль");
            double result = (currentOp == '*') ? left * right : left / right;
            values[i] = result;
            values.erase(values.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;  // Уменьшаем индекс, так как мы изменили размер вектора
        }
    }

    // Теперь обрабатываем оставшиеся операции
    double result = values[0];
    for (size_t i = 0; i < operators.size(); ++i) {
        char currentOp = operators[i];
        double right = values[i + 1];
        switch (currentOp) {
        case '+':
            result += right;
            break;
        case '-':
            result -= right;
            break;
        case '%':
            result = result * (right / 100.0);
            break;
        }
    }
    return result;
}

Calculator::Calculator(QObject *parent)
    : QObject(parent), _textContent("0"), _flag(true) {}

QString Calculator::textContent() const {
    return _textContent;
}

void Calculator::handleButton() {
    try {
        _textContent += " e";
        QString resultStr = QString::number(evaluateExpression(_textContent.toStdString()));
        _textContent.remove(_textContent.length() - 1, 1);
        addHistoryEntry(_textContent + "= " + resultStr);
        setTextContent(resultStr);
    } catch (const std::exception& e) {
        setTextContent(e.what());
    }
}

void Calculator::setTextContent(const QString &text) {
    if (_textContent != text) {
        _textContent = text;
        emit textContentChanged();
    }
}
