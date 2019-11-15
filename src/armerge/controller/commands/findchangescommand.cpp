#include "findchangescommand.h"
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

FindChangesCommand::FindChangesCommand(QString file)
{
    mFileName = file;
}

void FindChangesCommand::execute()
{

    std::vector<QString> sList = SettingsSingletone::getInstance()->getSettingList();
    QString pp(sList[SettingsSingletone::S_SOURCE_PATH].split("\\").join("/"));
    QString wp(sList[SettingsSingletone::S_BUILD_PATH].split("\\").join("/"));

    QDir d(wp);
    QString w = d.absolutePath() + mFileName.split(pp)[1];


    QFile src(mFileName);
    QFile dst(w);


    //finishCommand();
}

/*bool FindChangesCommand::checkWorkFolder(QString sourceFolder, QString destFolder)
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
*/
