#ifndef CHANGES_H
#define CHANGES_H

#include <QObject>
#include<string>

using namespace std;

enum eChangeType
{
    CT_ADD,
    CT_EDIT,
    CT_REMOVE
};

class Changes : public QObject
{
    Q_OBJECT
public:
    Changes(QObject *parent = nullptr);

    int line() const;
    void setLine(int line);

    string text() const;
    void setText(const string &text);

    eChangeType changeType() const;
    void setChangeType(const eChangeType &changeType);

    QString name() const;
    void setName(QString &name);

signals:

public slots:

private:
    QString mName;
    int mLine;
    string mText;
    eChangeType mChangeType;
};

#endif // CHANGES_H
