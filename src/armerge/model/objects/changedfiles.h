#ifndef CHANGEDFILES_H
#define CHANGEDFILES_H

#include <QObject>
#include<vector>
#include<memory>
#include"model/objects/changes.h"

using namespace std;

class ChangedFiles : public QObject
{
    Q_OBJECT
public:
    explicit ChangedFiles(QObject *parent = nullptr);

    void setName(QString& name);
    const QString& getName() const ;

signals:

public slots:

private:
    QString mName;
    vector<shared_ptr<Changes>> mChanges;
};

#endif // CHANGEDFILES_H
