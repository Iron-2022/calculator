#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "counter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // регистрация типа Counter
    engine.rootContext()->setContextProperty("textContent", "Hello METANIT.COM");
    engine.rootContext()->setContextProperty("textSize", 22);
    qmlRegisterType<Calculator>("counter", 1, 0,"Counter");

    const QUrl url("qrc:/path/main.qml");
    engine.load(url);
    return app.exec();
}
