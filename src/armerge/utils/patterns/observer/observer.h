#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"

class Subject;
struct sSubjectEventType;

class Observer
{
public:
    Observer(Subject* mod, int div);

    virtual void update(sSubjectEventType* event) = 0;

protected:
    Subject* getSubject();
    int getDivisor();

private:
    int mDenom;
    Subject* mModel;

};

#endif // OBSERVER_H
