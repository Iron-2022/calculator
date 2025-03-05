#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "counter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // регистрация типа Counter
    qmlRegisterType<Calculator>("counter", 1, 0,"Counter");
    qmlRegisterType<DataModel>("History", 1, 0, "DataModel");

    const QUrl url("qrc:/path/main.qml");
    engine.load(url);
    return app.exec();
}
