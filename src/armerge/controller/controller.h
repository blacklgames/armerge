#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "QObject"
#include "utils/patterns/observer/observer.h"
#include "controller/commands/command.h"

class Controller : public Observer, public QObject
{
public:
    Controller();

    void update(int event);

private:
    Command* mCommand;
};

#endif // CONTROLLER_H
