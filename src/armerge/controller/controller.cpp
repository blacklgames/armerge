#include "controller.h"
#include "controller/communication/controllersubject.h"
#include "controller/commands/initcommand.h"
#include <memory>
#include <QThread>

Controller::Controller()
{

}

void Controller::startCommandThread(Command* command)
{
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

void Controller::update(int event)
{
    Command* command = nullptr;
    shared_ptr<Command> cmd(command);
    switch(event)
    {
    case ControllerSubject::INIT:
        command = new InitCommand();
        connect(static_cast<InitCommand*>(command)->getFileWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));

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
cout << "start commad" << endl;
    startCommandThread(command);
}

void Controller::stopAll()
{

}

void Controller::handleFileChanged(const QString& name)
{
    cout << "file " + name.toStdString() + " has been chaged " << endl;
}
