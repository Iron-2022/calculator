#include "counter.h"
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

bool symbolic_correctness(std::string stroka){
    return (stroka != "e" && stroka != "+" && stroka != "-" && stroka != "*" && stroka != "/");
}

double evaluateExpression(const std::string& expression) {
    std::istringstream stream(expression);
    std::vector<double> values;
    std::vector<char> operators;

    double num;
    char op;
    std::string str;

    // Читаем первое число
    stream >> str;
    if (symbolic_correctness(str)) values.push_back(std::stod(str));
    else throw std::runtime_error("Не верный формат выражения");

    while (stream >> op) {
        // Читаем следующее число
        stream >> str;
        if (symbolic_correctness(str)) num = std::stod(str);
        else throw std::runtime_error("Не верный формат выражения");
        operators.push_back(op);
        values.push_back(num);
    }

    // Обрабатываем операторы в порядке их приоритета
    for (size_t i = 0; i < operators.size(); ++i) {
        char currentOp = operators[i];
        if (currentOp == '*' || currentOp == '/') {
            double left = values[i];
            double right = values[i + 1];
            if (currentOp == '/' && right == 0)throw std::runtime_error("Не верный формат выражения");
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
        switch (currentOp){
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

Calculator::Calculator(QObject *parent) : QObject(parent), text_content("0"), flag(true){}

QString Calculator::textContent() const {
    return text_content;
}


/*void Calculator::click_dot(){
    if(flag){

    }else{

    }
}*/
void Calculator::handleButton() {
    try{
        text_content += " e";
        QString result = QString::number(evaluateExpression(text_content.toStdString()));
        text_content.remove(text_content.length() - 1, 1);
        addHistoryEntry(text_content + "= " + result);
        setTextContent(result);
    }catch (const std::exception& e){
        setTextContent(e.what());
    }
}

void Calculator::setTextContent(const QString &text) {
    if (text_content != text) {
        text_content = text;
        emit textContentChanged();
    }
}
