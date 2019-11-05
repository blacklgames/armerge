#ifndef ControllerSUBJECT_H
#define ControllerSUBJECT_H

#include "utils/patterns/observer/subject.h"

class ControllerSubject : public Subject
{
public:
    enum eControllerEvents
    {
        INIT,
        FIX_CHANGES,
        REMOVE_SELECTED,
        CLEAR_ALL,
        MOVE_YOR_SELECTED,
        MOVE_YOUR_ALL,
        REMOVE_CURRENT_SELECTED,
        REMOVE_CURRENT_ALL
    };

public:
    ControllerSubject();
};

#endif // VIEWSUBJECT_H
