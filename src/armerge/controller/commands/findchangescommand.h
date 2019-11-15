#ifndef FINDCHANGESCOMMAND_H
#define FINDCHANGESCOMMAND_H

#include <QObject>
#include "command.h"

class FindChangesCommand : public Command
{
    Q_OBJECT
public:
    FindChangesCommand(QString file);

signals:

public slots:
    virtual void execute();

private:
    QString mFileName;
};

#endif // FINDCHANGESCOMMAND_H
