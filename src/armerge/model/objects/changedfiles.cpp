#include "changedfiles.h"

ChangedFiles::ChangedFiles(QObject *parent) : QObject(parent)
{

}

void ChangedFiles::setName(QString name)
{
    mName = name;
}

QString ChangedFiles::getName() const
{
    return mName;
}
