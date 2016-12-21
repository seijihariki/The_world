//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_SUBJECT_HPP
#define THE_WORLD_SUBJECT_HPP

#include <set>
#include "../Base/Event.hpp"
#include "../Base/Entity.hpp"

namespace TheWorldEngine
{
    namespace ObserverPattern
    {
        class Subject;

        class Observer
        {
        public:
            virtual void onNotify(Event::Event event) = 0;
            ~Observer();

        protected:
            bool addToSubject(Subject *subject);
            bool removeFromSubject(Subject *subject);

        private:
            std::set<Subject*> subjects;
        };

        class Subject
        {
        public:
            bool addObserver(Observer *observer);
            bool hasObserver(Observer *observer) const;
            bool removeObserver(Observer *observer);

        protected:
            void notify(Event::Event event);
        private:
            std::set<Observer*> observers;
        };

    }
}

#endif //THE_WORLD_SUBJECT_HPP
