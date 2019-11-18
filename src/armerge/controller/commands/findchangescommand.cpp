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
#include <QDebug>
#include <QElapsedTimer>
#include "utils/xml/pugixml.hpp"

struct simple_walker: pugi::xml_tree_walker
{
    virtual bool for_each(pugi::xml_node& node)
    {
        for (int i = 0; i < depth(); ++i) std::cout << "  ";

        std::cout << "depth " << depth() << "  " <<  node.type() << ": name='" << node.name() << "', value='" << node.value() << "'\n";

        return true;
    }
};

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

    pugi::xml_document src;
    pugi::xml_document dst;
    pugi::xml_parse_result result;

    result = src.load_file(mFileName.toStdString().c_str());
    std::cout << "Load result for source: " << result.description() << endl;

    result = dst.load_file(w.toStdString().c_str());
    std::cout << "Load result for destination: " << result.description() << endl;

    QElapsedTimer timer;
    simple_walker walker;
    timer.start();

    src.findDiff(walker, dst.getRoot());

    qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";

    finishCommand();
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
