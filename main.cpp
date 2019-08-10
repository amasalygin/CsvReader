#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QSortFilterProxyModel>

#include "personmodel.h"
#include "proxymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    PersonModel *model = new PersonModel();
    ProxyModel *proxyModel = new ProxyModel();
    proxyModel->setSourceModel(model);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("PersonModel", proxyModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
