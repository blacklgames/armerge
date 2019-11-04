#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <iostream>
#include <vector>

using namespace std;

struct sSubjectEventType
{
    int value;
};

class Subject
{
private:
    vector<class Observer *> mViews;

public:
    Subject();

    void notify(sSubjectEventType* event);
    void attach(Observer* obs);
};

#endif // SUBJECT_H
