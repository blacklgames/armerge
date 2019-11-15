#ifndef FixChangesCommand_H
#define FixChangesCommand_H

#include <QFileSystemWatcher>
#include "controller/commands/command.h"
#include "QString"

class FixChangesCommand : public Command
{
    Q_OBJECT

public:
    FixChangesCommand();
    virtual ~FixChangesCommand();
    QFileSystemWatcher* getFileWatcher();

public slots:
    virtual void execute();

signals:
    void fileChanged(const QString& name);

private:
    bool checkWorkFolder(QString src, QString dst, bool isExist);

private:
    QFileSystemWatcher* mFileWatcher;
};

#endif // FixChangesCommand_H
