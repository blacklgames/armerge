#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include<vector>
#include "objects/changedfiles.h"
#include "objects/changes.h"
#include <memory>

using vFiles = std::vector<std::shared_ptr<ChangedFiles>>;
using vChanges = std::vector<std::shared_ptr<Changes>>;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

// interface to view
     const vFiles& getChangedFiles() const;

/////////////////////////////////////////

signals:
    void updateView();

public slots:
    void addChangedFile(QString name, bool isChanged);
    void addChangesToFile(const QString& name, const QString& changes);
    void clearAllFiles();

    void updateChanges(Changes* changes);

private:
    vFiles mChangedFiles;
    vChanges mChanges;

};

#endif // MODEL_H
