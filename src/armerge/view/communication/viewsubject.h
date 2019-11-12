#ifndef VIEWSUBJECT_H
#define VIEWSUBJECT_H

#include "utils/patterns/observer/subject.h"
#include "model/model.h"

class ViewSubject : public Subject
{
public:
    enum eViewEvents
    {
        FIX_CHANGES,
        REMOVE_SELECTED,
        CLEAR_ALL,
        MOVE_YOR_SELECTED,
        MOVE_YOUR_ALL,
        REMOVE_CURRENT_SELECTED,
        REMOVE_CURRENT_ALL,
        INIT
    };

public:
    ViewSubject();

    virtual void updateView() = 0;
    void setModel(Model* model);

protected:
    Model* mModel;
};

#endif // VIEWSUBJECT_H
