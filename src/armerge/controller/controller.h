#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "QObject"
#include "model/model.h"
#include "utils/patterns/observer/observer.h"
#include "controller/commands/command.h"

class Controller :  public QObject, public Observer
{
    Q_OBJECT

public:
    Controller();
    void update(int event);
    void setModel(Model *model);

private:
    void startCommandThread(Command* cmd);
    bool quickFileCompire(QString file);

public slots:
    void handleInitFileChanged(const QString& name);
    void handleFileChanged(const QString& name);

    void findChanges(Changes* changes);

private slots:
    void threadFinished();

signals:
    void addChangedFile(const QString& name, bool isChanged);
    void addChangesToFile(const QString& name, const QString& changes);
    void clearAllFiles();

    void updateChanges(Changes* changes);

private:
    void stopAllCommads();

private:
    Model* mModel;
    vector<Command*> mCommandList;
};

#endif // CONTROLLER_H
