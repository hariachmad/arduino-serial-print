#include "Subject.h"

void Subject::attach(IObserver *observer)
{
    if (observerCount < MAX_OBSERVERS)
    {
        observers[observerCount++] = observer;
    }
}

void Subject::detach(IObserver *observer)
{
    for (int i = 0; i < observerCount; i++)
    {
        if (observers[i] == observer)
        {
            for (int j = i; j < observerCount - 1; j++)
            {
                observers[j] = observers[j + 1];
            }
            observerCount--;
            break;
        }
    }
}

void Subject::notify()
{
    for (int i = 0; i < observerCount; i++)
    {
        observers[i]->update();
    }
}

Subject::~Subject()
{
    for (int i = 0; i < observerCount; ++i)
    {
        delete observers[i];
    }
}