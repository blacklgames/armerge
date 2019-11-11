#ifndef INITCOMMAND_H
#define INITCOMMAND_H

#include <QFileSystemWatcher>
#include "controller/commands/command.h"
#include "QString"

class InitCommand : public Command
{
    Q_OBJECT

public:
    InitCommand();
    virtual ~InitCommand();
    QFileSystemWatcher* getFileWatcher();

public slots:
    virtual void execute();

signals:
    void fileChanged(const QString& name);

private:
    bool checkWorkFolder(QString src, QString dst, bool isExist);
    bool removeDir(const QString & dirName);
    bool quickFileCompire(QString src, QString dst);

private:
    QFileSystemWatcher* mFileWatcher;
};

#endif // INITCOMMAND_H
