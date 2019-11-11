#include "controller.h"
#include "controller/communication/controllersubject.h"
#include "controller/commands/initcommand.h"
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
}

void Controller::startCommandThread(Command* command)
{
    if(nullptr != command)
    {
        QThread* thread = new QThread;
        command->moveToThread(thread);
        connect(thread, SIGNAL(started()), command, SLOT(execute()));
        connect(command, SIGNAL(finished()), thread, SLOT(quit()));
        //connect(this, SIGNAL(stopAll()), command, SLOT(stop()));
        connect(command, SIGNAL(finished()), command, SLOT(deleteLater()));
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
        connect(static_cast<InitCommand*>(command)->getFileWatcher(), SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));
        connect(static_cast<InitCommand*>(command), SIGNAL(fileChanged(const QString&)), this, SLOT(handleFileChanged(const QString&)));

        break;
    case ControllerSubject::FIX_CHANGES:

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

void Controller::handleFileChanged(const QString& name)
{
    bool isChanged = !quickFileCompire(name);
    if(isChanged)
    {
           //TODO: deep analize
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

