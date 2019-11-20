#include "model/objects/changes.h"

Changes::Changes(QObject *parent)
{

}

int Changes::line() const
{
    return mLine;
}

void Changes::setLine(int line)
{
    mLine = line;
}

string Changes::text() const
{
    return mText;
}

void Changes::setText(const string &text)
{
    mText = text;
}

eChangeType Changes::changeType() const
{
    return mChangeType;
}

void Changes::setChangeType(const eChangeType &changeType)
{
    mChangeType = changeType;
}

QString Changes::name() const
{
    return mName;
}

void Changes::setName(QString &name)
{
    mName = name;
}
