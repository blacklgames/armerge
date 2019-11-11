#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include<vector>
#include "objects/changedfiles.h"
#include "objects/changes.h"
#include <memory>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

signals:

public slots:
    void addChangedFile(QString name, bool isChanged);
    void addChangesToFile(const QString& name, const QString& changes);

private:
    std::vector<std::shared_ptr<ChangedFiles>> mChangedFiles;
    std::vector<std::shared_ptr<Changes>> mChanges;

};

#endif // MODEL_H
