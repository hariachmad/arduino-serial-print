#ifndef SUBJECT_H
#define SUBJECT_H

#include "IObserver.h"

#define MAX_OBSERVERS 5

class Subject {
public:
    Subject() : observerCount(0) {}
    
    void attach(IObserver* observer) ;
    
    void detach(IObserver* observer) ;
    
    void notify();

    virtual ~Subject();

protected:
    IObserver* observers[MAX_OBSERVERS];
    int observerCount;
};

#endif