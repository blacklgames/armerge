#include "controller.h"
#include "controller/communication/controllersubject.h"
#include "controller/commands/initcommand.h"
#include "controller/commands/fixchangescommand.h"
#include "controller/commands/findchangescommand.h".h"
#include "settingssingletone.h"

#include <memory>
#include <QThread>
#include <string>
#include <fstream>
#include <streambuf>
#include <iterator>

Controller::Controller()
{

}


void Controller::setModel(Model* model)
{
    mModel = model;
    connect(this, SIGNAL(addChangedFile(const QString&, bool)), mModel, SLOT(addChangedFile(QString, bool)));
    connect(this, SIGNAL(clearAllFiles()), mModel, SLOT(clearAllFiles()));
}

void Controller::startCommandThread(Command* command)
{
    if(nullptr != command)
    {
        QThread* thread = new QThread;
        command->moveToThread(thread);
        mCommandList.push_back(command);
        connect(thread, SIGNAL(started()), command, SLOT(execute()));
        connect(command, SIGNAL(finished()), thread, SLOT(quit()));
        connect(command, SIGNAL(finished()), this, SLOT(threadFinished()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
}

void Controller::update(int event)
{
    Command* command = nullptr;
    shared_ptr<Command> cmd(command);

    switch(event)
    {
    case ControllerSubject::INIT:
        command = new InitCommand();
        connect(static_cast<InitCommand*>(command), SIGNAL(fileChanged(const QString&)), this, SLOT(handleInitFileChanged(const QString&)));
        connect(static_cast<InitCommand*>(command)->getFileWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));
        break;
    case ControllerSubject::FIX_CHANGES:
        stopAllCommads();
        command = new FixChangesCommand();
        connect(static_cast<FixChangesCommand*>(command)->getFileWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));
        emit clearAllFiles();
        break;
    case ControllerSubject::REMOVE_SELECTED:

        break;
    case ControllerSubject::CLEAR_ALL:

        break;
    case ControllerSubject::MOVE_YOR_SELECTED:

        break;
    case ControllerSubject::MOVE_YOUR_ALL:

        break;
    case ControllerSubject::REMOVE_CURRENT_SELECTED:

        break;
    case ControllerSubject::REMOVE_CURRENT_ALL:

        break;
    default:

        break;

    }
    startCommandThread(command);
}

void Controller::handleInitFileChanged(const QString& name)
{
    FindChangesCommand* cmd = new FindChangesCommand(name);
    startCommandThread(cmd);
    emit addChangedFile(name, true);
}

void Controller::handleFileChanged(const QString& name)
{
    bool isChanged = !quickFileCompire(name);
    if(isChanged)
    {
        FindChangesCommand* cmd = new FindChangesCommand(name);
        startCommandThread(cmd);
    }
    emit addChangedFile(name, isChanged);
}

bool Controller::quickFileCompire(QString file)
{
    std::vector<QString> sList = SettingsSingletone::getInstance()->getSettingList();
    QString pp(sList[SettingsSingletone::S_SOURCE_PATH]);
    QString wp(sList[SettingsSingletone::S_BUILD_PATH]);
    QString path(file.split(pp.split("\\").join("/"))[1]);

    std::ifstream stream{pp.append(path).toStdString()};
    std::string file1{std::istreambuf_iterator<char>(stream),
                    std::istreambuf_iterator<char>()};

    stream = std::ifstream{wp.append(path).toStdString()};
    std::string file2{std::istreambuf_iterator<char>(stream),
                    std::istreambuf_iterator<char>()};

    return file1 == file2;
}

void Controller::stopAllCommads()
{
    foreach (auto cmd, mCommandList) {
        if(cmd->thread()->isRunning())
        cmd->thread()->requestInterruption();
    }
}

void Controller::threadFinished()
{
    mCommandList.erase(
        std::remove_if(mCommandList.begin(), mCommandList.end(),[](Command* x) {
                    return x->isFinished();}),
        mCommandList.end());
}
