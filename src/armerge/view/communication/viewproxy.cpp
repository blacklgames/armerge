#include "viewproxy.h"
#include "viewsubject.h"
#include <QDebug>

void ViewProxy::update(int event)
{
    switch(event)
    {
    case ViewSubject::FIX_CHANGES:
        notify(ControllerSubject::FIX_CHANGES);
        //qInfo() << "FIX_CHANGES";
        break;
    case ViewSubject::REMOVE_SELECTED:
        notify(ControllerSubject::REMOVE_SELECTED);
        //qInfo() << "REMOVE_SELECTED";
        break;
    case ViewSubject::CLEAR_ALL:
        notify(ControllerSubject::FIX_CHANGES);
        //qInfo() << "CLEAR_ALL";
        break;
    case ViewSubject::MOVE_YOR_SELECTED:
        notify(ControllerSubject::FIX_CHANGES);
        //qInfo() << "MOVE_YOR_SELECTED";
        break;
    case ViewSubject::MOVE_YOUR_ALL:
        notify(ControllerSubject::MOVE_YOUR_ALL);
        //qInfo() << "MOVE_YOUR_ALL";
        break;
    case ViewSubject::REMOVE_CURRENT_SELECTED:
        notify(ControllerSubject::REMOVE_CURRENT_SELECTED);
        //qInfo() << "REMOVE_CURRENT_SELECTED";
        break;
    case ViewSubject::REMOVE_CURRENT_ALL:
        notify(ControllerSubject::REMOVE_CURRENT_ALL);
        //qInfo() << "REMOVE_CURRENT_ALL";
        break;
    case ViewSubject::INIT:
        notify(ViewSubject::INIT);
        //qInfo() << "REMOVE_CURRENT_ALL";
        break;
    default:
        //qInfo() << "default";
        break;

    }
}
