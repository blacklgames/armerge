#include "observer.h"
#include "subject.h"

Observer::Observer(Subject* mod, int div)
{
    mModel = mod;
    mDenom = div;
    mModel->attach(this);
}

Subject* Observer::getSubject()
{
    return mModel;
}

int Observer::getDivisor()
{
    return mDenom;
}

