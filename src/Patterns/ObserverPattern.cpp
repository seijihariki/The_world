//
// Created by seijihariki on 18/12/2016.
//

#include "ObserverPattern.hpp"

TheWorldEngine::ObserverPattern::Observer::~Observer()
{
    for (auto subject : subjects)
        removeFromSubject(subject);
}

bool TheWorldEngine::ObserverPattern::Observer::addToSubject(Subject *subject)
{
    if (!subject)
        return false;
    return subject->addObserver(this) || subjects.insert(subject).second;
}

bool TheWorldEngine::ObserverPattern::Observer::removeFromSubject(Subject *subject)
{
    if (!subject)
        return false;
    return subject->removeObserver(this) || subjects.erase(subject);
}

bool TheWorldEngine::ObserverPattern::Subject::addObserver(Observer *observer)
{
    return observers.insert(observer).second;
}

bool TheWorldEngine::ObserverPattern::Subject::hasObserver(Observer *observer) const
{
    return observers.find(observer) != observers.end();
}

bool TheWorldEngine::ObserverPattern::Subject::removeObserver(Observer *observer)
{
    return (bool) observers.erase(observer);
}

void TheWorldEngine::ObserverPattern::Subject::notify(Event::Event event)
{
    for (auto observer : observers)
        observer->onNotify(event);
}

