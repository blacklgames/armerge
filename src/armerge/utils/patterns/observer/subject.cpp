#include "subject.h"

Subject::Subject()
{

}

void Subject::notify(sSubjectEventType* event)
{
    for (size_t i = 0; i < mViews.size(); ++i) {
        mViews[i]->update(event);
    }
}

void Subject::attach(Observer* obs)
{
    mViews.push_back(obs);
}
