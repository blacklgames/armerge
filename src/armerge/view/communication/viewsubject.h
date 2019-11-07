#ifndef VIEWSUBJECT_H
#define VIEWSUBJECT_H

#include "utils/patterns/observer/subject.h"

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
};

#endif // VIEWSUBJECT_H
