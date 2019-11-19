
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
