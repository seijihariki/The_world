//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_EVENT_HPP
#define THE_WORLD_EVENT_HPP

#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>

namespace TheWorldEngine
{
    namespace Event
    {
        enum EventType
        {
            PHYSICS_EVENT,
            SYSTEM_EVENT
        };

        enum DataType
        {
            INTEGER,
            DOUBLE,
            STRING,
            SFML,
            POINTER
        };

        union EventData
        {
        public:
            long long int integer;
            double dfloat;
            sf::Event sfml;
        };

        class Event
        {
        public:
            Event(EventType type, EventData data, DataType data_type) : type(type), data(data), data_type(data_type) {}

            const EventType getType() const {return type;}
            const EventData getData() const {return data;}
            const DataType getDataType() const {return data_type;}
        private:
            const EventType type;
            const EventData data;
            const DataType data_type;
        };
    }
}

#endif //THE_WORLD_EVENT_HPP
