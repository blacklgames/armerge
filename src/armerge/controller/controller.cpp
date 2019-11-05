#include "controller.h"
#include "controller/communication/controllersubject.h"
#include "controller/commands/initcommand.h"

Controller::Controller()
{
    update(ControllerSubject::INIT);
}

void Controller::update(int event)
{
    Command* command = nullptr;

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
        command->execute();
        delete command;
    }
}
