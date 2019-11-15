#include "FixChangesCommand.h"
#include <iostream>
#include <direct.h>
//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <CString>
#include "settingssingletone.h"
#include "QDir"
#include <string>
#include <fstream>
#include <streambuf>
#include <iterator>
#include <QThread>

using namespace std;

FixChangesCommand::FixChangesCommand()
{
    mFileWatcher = new QFileSystemWatcher();
}

FixChangesCommand::~FixChangesCommand()
{
    delete mFileWatcher;
}

QFileSystemWatcher* FixChangesCommand::getFileWatcher()
{
    return mFileWatcher;
}

void FixChangesCommand::execute()
{
    std::cout << "execute fix command " << std::endl;

    std::vector<QString> sList = SettingsSingletone::getInstance()->getSettingList();
    QString pp(sList[SettingsSingletone::S_SOURCE_PATH]);
    QString wp(sList[SettingsSingletone::S_BUILD_PATH]);

    QDir d(wp);
    checkWorkFolder(pp, wp, !d.exists());
    finishCommand();


    //removeDir(QString("D:/work/GM/source/new_E2/GM_E2_MY21_VP/gm.di.e4.bsp.delivery/di.gen.2022.gm.e4.vip.bsw.cfg/project/Config/tmp"));
}

bool FixChangesCommand::checkWorkFolder(QString sourceFolder, QString destFolder, bool isNew)
{
    if(this->thread()->isInterruptionRequested())
        return false;

    bool success = false;
    QDir sourceDir(sourceFolder);

    if(!sourceDir.exists())
        return false;

    QDir destDir(destFolder);
    if(!destDir.exists())
        destDir.mkdir(destFolder);

    QStringList files = sourceDir.entryList(QDir::Files);
    for(int i = 0; i< files.count(); i++) {
        if(this->thread()->isInterruptionRequested())
            return false;
        QString srcName = sourceDir.absolutePath() + QDir::separator() + files[i];
        QString destName = destDir.absolutePath() + QDir::separator() + files[i];
        QFile::remove(destName);
        success = QFile::copy(srcName, destName);
        if(!success)
            return false;

        mFileWatcher->addPath(srcName);
    }

    files.clear();
    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(int i = 0; i< files.count(); i++)
    {
        if(this->thread()->isInterruptionRequested())
            return false;
        QString srcName = sourceDir.absolutePath() + QDir::separator() + files[i];
        QString destName = destDir.absolutePath() + QDir::separator() + files[i];
        success = checkWorkFolder(srcName, destName, isNew);
        if(!success)
            return false;
    }

    return true;
}
