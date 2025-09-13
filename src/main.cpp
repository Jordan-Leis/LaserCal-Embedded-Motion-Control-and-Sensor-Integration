#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "calibration_manager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CalibrationManager calib;
    engine.rootContext()->setContextProperty("calibrationManager", &calib);
    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
