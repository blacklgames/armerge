#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include<string>

using namespace std;

class Command : public QObject
{
    Q_OBJECT

public:
    Command();
    virtual ~Command();

public slots:
    virtual void execute();
    void stop();

signals:
    void finished();

};

#endif // COMMAND_H
