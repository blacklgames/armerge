#ifndef CONTROLLERPROXY_H
#define CONTROLLERPROXY_H

#include "utils/patterns/observer/observer.h"
#include "utils/patterns/observer/subject.h"

class ControllerProxy : public Observer, public Subject
{
public:
    void update(int event);
};

#endif // CONTROLLERPROXY_H
