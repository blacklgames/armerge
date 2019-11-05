#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

class Subject;
struct sSubjectEventType;

class Observer
{
public:
    virtual void update(int event) = 0;

private:

};

#endif // OBSERVER_H
