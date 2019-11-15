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

    bool isFinished();

public slots:
    virtual void execute();

signals:
    void finished();

protected:
    void finishCommand();

private:
    bool mIsFinished;

};

#endif // COMMAND_H
