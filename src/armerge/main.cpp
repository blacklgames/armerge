#include "view/mainwindow.h"
#include <QApplication>
#include "view/communication/viewproxy.h"
#include "controller/communication/controllerproxy.h"
#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ViewProxy* vp = new ViewProxy();
    ControllerProxy* cp = new ControllerProxy();
    Controller* contoller = new Controller();
    vp->attach(cp);
    cp->notify(ControllerSubject::INIT);
    cp->attach(contoller);
    w.setProxy(vp);
    w.init();
    w.show();

    return a.exec();
}
