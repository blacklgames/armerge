#include "model.h"
#include <iostream>


Model::Model(QObject *parent) : QObject(parent)
{

}

const vFiles& Model::getChangedFiles() const
{
    return mChangedFiles;
}

void Model::clearAllFiles()
{
    cout << "clearAllFiles" << endl;
    mChangedFiles.clear();
    emit updateView();
}

void Model::addChangedFile(QString name, bool isChanged)
{
    bool present = false;

    auto it = mChangedFiles.begin();
    for(; it != mChangedFiles.end(); ++it)
    {
        if((*it)->getName() == name)
        {
            if(!isChanged)
                mChangedFiles.erase(it);
            present = true;
            break;
        }
    }
    if(!present)
    {
        std::shared_ptr<ChangedFiles> file(new ChangedFiles());
        file->setName(name);
        mChangedFiles.push_back(file);
    }
    emit updateView();
}

void Model::addChangesToFile(const QString& name, const QString& changes)
{

}

void Model::updateChanges(Changes* changes)
{
    for (auto ch : mChangedFiles) {
        if(ch->name() == changes->name())
        {

        }
    }
}
