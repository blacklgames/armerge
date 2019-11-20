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
    timer.start();

    findDiff(src, dst);

    qDebug() << "The slow operation took" << timer.elapsed() << "milliseconds";

    finishCommand();
}

bool FindChangesCommand::findDiff(xml_document& src, xml_document& dst)
{
    simple_walker walker;

    walker._depth = -1;

    xml_node cur = src.root();
    xml_node dst_cur = dst.root();

    if (cur && dst_cur)
    {
        ++walker._depth;

        do
        {
            xml_node srcVal(cur);
            xml_node dstVal(dst_cur);


            //std::cout << "depth " << walker.depth() << "  " <<  srcVal.type() << ": name='" << srcVal.name() << "', value='" << srcVal.value() << "'\n";
            //std::cout << "depth " << walker.depth() << "  " <<  dstVal.type() << ": name='" << dstVal.name() << "', value='" << dstVal.value() << "'\n";

            if(srcVal.name() != dstVal.name())
            {
                Changes* ch = new Changes();
                ch->setName(mFileName);
                ch->setText("text");
                ch->setLine(walker.depth());
                emit findChanges(ch);
            }
            else if(srcVal.value() != dstVal.value())
            {
                Changes* ch = new Changes();
                ch->setName(mFileName);
                ch->setText("text");
                ch->setLine(walker.depth());
                emit findChanges(ch);
            }

            if (cur.first_child())
            {
                ++walker._depth;
                cur = cur.first_child();
                dst_cur = dst_cur.first_child();
            }
            else if (cur.next_sibling())
            {
                cur = cur.next_sibling();
                dst_cur = dst_cur.next_sibling();
            }
            else
            {
                while (!cur.next_sibling() && cur != src.root() && cur.parent())
                {
                    --walker._depth;
                    cur = cur.parent();
                    dst_cur = dst_cur.parent();
                }

                if (cur != src.root())
                    cur = cur.next_sibling();
                    dst_cur = dst_cur.next_sibling();
            }
        }
        while (cur && cur != src.root());
    }

    xml_node arg_end(src.root());
    xml_node dst_arg_end(dst.root());
    return walker.end(arg_end) && walker.end(dst_arg_end);
}

