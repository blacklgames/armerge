#include "initcommand.h"
#include <iostream>
#include <direct.h>
//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <CString>
#include "settingssingletone.h"
#include "QDir"

using namespace std;

InitCommand::InitCommand()
{

}

void InitCommand::execute()
{
    std::cout << "execute init command " << std::endl;\

    std::vector<QString> sList = SettingsSingletone::getInstance()->getSettingList();
    QString pp(sList[SettingsSingletone::S_SOURCE_PATH]);
    QString wp(sList[SettingsSingletone::S_BUILD_PATH]);

    QDir d(wp);
    if(!d.exists())
    {
        QDir().mkdir(wp);
    }
    copyPath(pp, wp);
    //removeDir(QString("D:/work/GM/source/new_E2/GM_E2_MY21_VP/gm.di.e4.bsp.delivery/di.gen.2022.gm.e4.vip.bsw.cfg/project/Config/tmp"));
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

bool InitCommand::copyPath(QString sourceFolder, QString destFolder)
{
    bool success = false;
    QDir sourceDir(sourceFolder);

    if(!sourceDir.exists())
        return false;

    QDir destDir(destFolder);
    if(!destDir.exists())
        destDir.mkdir(destFolder);

    QStringList files = sourceDir.entryList(QDir::Files);
    for(int i = 0; i< files.count(); i++) {
        QString srcName = sourceFolder + QDir::separator() + files[i];
        QString destName = destFolder + QDir::separator() + files[i];
        success = QFile::copy(srcName, destName);
        if(!success)
            return false;
    }

    files.clear();
    files = sourceDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for(int i = 0; i< files.count(); i++)
    {
        QString srcName = sourceFolder + QDir::separator() + files[i];
        QString destName = destFolder + QDir::separator() + files[i];
        success = copyPath(srcName, destName);
        if(!success)
            return false;
    }

    return true;
}
