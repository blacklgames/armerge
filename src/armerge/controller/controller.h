#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "QObject"
#include "utils/patterns/observer/observer.h"
#include "controller/commands/command.h"

class Controller :  public QObject, public Observer
{
    Q_OBJECT

public:
    Controller();
    void update(int event);

private:
    void startCommandThread(Command* cmd);

public slots:
    void handleFileChanged(const QString& name);
    void stopAll();


private:
    Command* mCommand;
};

#endif // CONTROLLER_H
