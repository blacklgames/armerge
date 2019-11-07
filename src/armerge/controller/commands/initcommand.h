#ifndef INITCOMMAND_H
#define INITCOMMAND_H

#include "controller/commands/command.h"
#include "QString"

class InitCommand : public Command
{
public:
    InitCommand();
    virtual void execute();

    bool copyPath(QString src, QString dst);
    bool removeDir(const QString & dirName);
};

#endif // INITCOMMAND_H
