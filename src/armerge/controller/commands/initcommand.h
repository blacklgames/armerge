#ifndef INITCOMMAND_H
#define INITCOMMAND_H

#include <QFileSystemWatcher>
#include "controller/commands/command.h"
#include "QString"

class InitCommand : public Command
{
public:
    InitCommand();
    virtual ~InitCommand();

public slots:
    virtual void execute();

    bool checkWorkFolder(QString src, QString dst, bool isExist);
    bool removeDir(const QString & dirName);

    QFileSystemWatcher* getFileWatcher();

private:
    QFileSystemWatcher* mFileWatcher;
};

#endif // INITCOMMAND_H
