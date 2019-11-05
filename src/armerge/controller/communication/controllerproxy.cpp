#include "controllerproxy.h"
#include "controllersubject.h"
#include "view/communication/viewsubject.h"
#include <QDebug>

void ControllerProxy::update(int event)
{
    switch(event)
    {
    case ViewSubject::FIX_CHANGES:
        notify(ControllerSubject::FIX_CHANGES);
        break;
    case ViewSubject::REMOVE_SELECTED:
        notify(ControllerSubject::REMOVE_SELECTED);
        break;
    case ViewSubject::CLEAR_ALL:
        notify(ControllerSubject::CLEAR_ALL);
        break;
    case ViewSubject::MOVE_YOR_SELECTED:
        notify(ControllerSubject::MOVE_YOR_SELECTED);
        break;
    case ViewSubject::MOVE_YOUR_ALL:
        notify(ControllerSubject::MOVE_YOUR_ALL);
        break;
    case ViewSubject::REMOVE_CURRENT_SELECTED:
        notify(ControllerSubject::REMOVE_CURRENT_SELECTED);
        break;
    case ViewSubject::REMOVE_CURRENT_ALL:
        notify(ControllerSubject::REMOVE_CURRENT_ALL);
        break;
    default:
        qInfo() << "default";
        break;

    }
}
