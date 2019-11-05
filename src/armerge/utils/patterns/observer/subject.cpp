#include "subject.h"

Subject::Subject()
{
}

void Subject::notify(int event)
{
    if(mViews.size() < 100)
    {
        for (size_t i = 0; i < mViews.size(); ++i) {
            mViews[i]->update(event);
        }
    }
}

void Subject::attach(Observer* obs)
{
    mViews.push_back(obs);
}
