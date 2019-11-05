#ifndef VIEWPROXY_H
#define VIEWPROXY_H

#include "utils/patterns/observer/observer.h"
#include "controller/communication/controllersubject.h"

class ViewProxy : public Observer, public Subject
{
public:
    void update(int event);
};

#endif // VIEWPROXY_H
