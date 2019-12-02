#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "counter.h"
#include "liststring.h"

int main(int argc, char *argv[])
{
    {
        const QMetaObject meta = Counter::staticMetaObject;
        QObject *obj = meta.newInstance();
        QObject::connect(obj, SIGNAL(countChanged()), obj, SLOT(print()));

        meta.invokeMethod(obj, "increment");

        meta.invokeMethod(obj, "reset");
    }

    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView *view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/qml_integration.qml"));
    qmlRegisterType<Counter>("custom.Counter", 1, 0, "Counter");
    qmlRegisterType<ListStrings>("custom.ListStrings", 1, 0, "ListStrings");
    view->showFullScreen();

    return app->exec();
}
