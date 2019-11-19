#ifndef FINDCHANGESCOMMAND_H
#define FINDCHANGESCOMMAND_H

#include <QObject>
#include "command.h"
#include "utils/xml/pugixml.hpp"

using namespace pugi;

class FindChangesCommand : public Command
{
    Q_OBJECT
public:
    FindChangesCommand(QString file);
    bool findDiff(xml_document& src, xml_document& dst);

signals:

public slots:
    virtual void execute();

private:
    QString mFileName;
};

#endif // FINDCHANGESCOMMAND_H
