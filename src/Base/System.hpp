//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_SYSTEM_HPP
#define THE_WORLD_SYSTEM_HPP

#include <SFML/System/Thread.hpp>
#include <string>

namespace TheWorldEngine
{
    class System
    {
    public:
        System(std::string name);

    protected:
        void l_debug(std::string message, ...);
        void l_error(std::string message, ...);
        void l_info(std::string message, ...);
    private:
        std::string name;
    };

    class ThreadedSystem : public System
    {
    public:
        ThreadedSystem(std::string name);

        sf::Thread &getThreadReference() {return thread;}

        virtual bool toExecute() = 0;

        void startThread();
        void stopThread();

    private:
        void loop();

        sf::Thread thread;
    };
}

#endif //THE_WORLD_SYSTEM_HPP
