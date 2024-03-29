#include "initcommand.h"
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
#include<qthread.h>

using namespace std;

InitCommand::InitCommand()
{
    mFileWatcher = new QFileSystemWatcher();
}

InitCommand::~InitCommand()
{
    delete mFileWatcher;
}

QFileSystemWatcher* InitCommand::getFileWatcher()
{
    return mFileWatcher;
}

void InitCommand::execute()
{
    std::cout << "execute init command " << std::endl;

    std::vector<QString> sList = SettingsSingletone::getInstance()->getSettingList();
    QString pp(sList[SettingsSingletone::S_SOURCE_PATH]);
    QString wp(sList[SettingsSingletone::S_BUILD_PATH]);

    QDir d(wp);
    checkWorkFolder(pp, wp, !d.exists());
    finishCommand();
    //removeDir(QString("D:/work/GM/source/new_E2/GM_E2_MY21_VP/gm.di.e4.bsp.delivery/di.gen.2022.gm.e4.vip.bsw.cfg/project/Config/tmp"));
}

bool InitCommand::checkWorkFolder(QString sourceFolder, QString destFolder, bool isNew)
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
    for(int i = 0; i< files.count(); i++)
    {
        if(this->thread()->isInterruptionRequested())
            return false;
        QString srcName = sourceDir.absolutePath() + QDir::separator() + files[i];
        QString destName = destDir.absolutePath() + QDir::separator() + files[i];
        if(isNew) {
            success = QFile::copy(srcName, destName);
            if(!success) return false;
        }
        else if(!quickFileCompire(srcName, destName))
        {
            emit fileChanged(srcName);
        }

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

bool InitCommand::quickFileCompire(QString src, QString dst)
{
    std::ifstream stream{src.toStdString()};
    std::string file1{std::istreambuf_iterator<char>(stream),
                    std::istreambuf_iterator<char>()};

    stream = std::ifstream{dst.toStdString()};
    std::string file2{std::istreambuf_iterator<char>(stream),
                    std::istreambuf_iterator<char>()};

    return file1 == file2;
}

bool InitCommand::removeDir(const QString & dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }
    return result;
}
