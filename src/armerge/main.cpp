#include "view/mainwindow.h"
#include <QApplication>
#include "view/communication/viewproxy.h"
#include "controller/communication/controllerproxy.h"
#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ViewProxy *vp = new ViewProxy();
    Controller *contoller = new Controller();
    ControllerProxy *cp = new ControllerProxy();
    Model *model = new Model();

    w.setModel(model);
    vp->attach(cp);
    cp->attach(contoller);
    contoller->setModel(model);

    w.setProxy(vp);
    w.init();
    w.show();
    return a.exec();
}
