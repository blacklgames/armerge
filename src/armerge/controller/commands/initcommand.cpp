#include "initcommand.h"
#include <iostream>
#include <direct.h>
//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <CString>

#include "QDir"

using namespace std;

InitCommand::InitCommand()
{

}

void InitCommand::execute()
{
    std::cout << "execute init command " << std::endl;\

    int isExist = _chdir(WORKING_PATH.c_str());
    cout << isExist << endl;
    if(isExist == -1)
    {
        _mkdir(WORKING_PATH.c_str());
        copyPath(QString::fromStdString(PROJECT_PATH), QString::fromStdString(WORKING_PATH));
    }

}

bool InitCommand::copyPath(QString srcFilePath, QString tgtFilePath)
{
    QFileInfo srcFileInfo(srcFilePath);
    if (srcFileInfo.isDir())
    {
        QDir targetDir(tgtFilePath);
        targetDir.cdUp();

        if (!targetDir.mkdir(QFileInfo(tgtFilePath).fileName()))
        {
            return false;
        }

        QDir sourceDir(srcFilePath);
        QStringList fileNames = sourceDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);

        foreach (const QString &fileName, fileNames)
        {
            const QString newSrcFilePath = srcFilePath + QLatin1Char('/') + fileName;
            const QString newTgtFilePath = tgtFilePath + QLatin1Char('/') + fileName;
            if (!copyPath(newSrcFilePath, newTgtFilePath))
                return false;
        }
    }
    else
    {
        if (!QFile::copy(srcFilePath, tgtFilePath))
        {
            cout << "copy false" << endl;
            return false;
        }
    }
    return true;
}
