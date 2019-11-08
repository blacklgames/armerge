#include "controller.h"
#include "controller/communication/controllersubject.h"
#include "controller/commands/initcommand.h"
#include <memory>
#include <QThread>

Controller::Controller()
{

}

void Controller::update(int event)
{
    Command* command = nullptr;
    shared_ptr<Command> cmd(command);
    switch(event)
    {
    case ControllerSubject::INIT:
        command = new InitCommand();

        break;
    case ControllerSubject::FIX_CHANGES:

        break;
    case ControllerSubject::REMOVE_SELECTED:

        break;
    case ControllerSubject::CLEAR_ALL:

        break;
    case ControllerSubject::MOVE_YOR_SELECTED:

        break;
    case ControllerSubject::MOVE_YOUR_ALL:

        break;
    case ControllerSubject::REMOVE_CURRENT_SELECTED:

        break;
    case ControllerSubject::REMOVE_CURRENT_ALL:

        break;
    default:

        break;

    }

    if(nullptr != command)
    {
        QThread* thread = new QThread;
        command->moveToThread(thread);
        connect(thread, SIGNAL(started()), command, SLOT(execute()));
        connect(command, SIGNAL(finished()), thread, SLOT(quit()));
        connect(this, SIGNAL(stopAll()), command, SLOT(stop()));
        connect(command, SIGNAL(finished()), command, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}
