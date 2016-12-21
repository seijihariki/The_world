//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_WINDOWCONTROLLER_HPP
#define THE_WORLD_WINDOWCONTROLLER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include "../Patterns/ObserverPattern.hpp"
#include "../Base/Types.hpp"
#include "../Base/System.hpp"

namespace TheWorldEngine
{
    namespace WindowController
    {
        class Window
        {
        public:
            Window(uint64_t wid, sf::VideoMode videoMode, const std::string &title, sf::Uint32 style = sf::Style::Default,
                   const sf::ContextSettings &settings = sf::ContextSettings());
            uint64_t getWID() {return wid;}
            sf::RenderWindow &getWindowReference() {return window;}
        private:
            uint64_t wid;
            sf::RenderWindow window;
        };

        class WindowController : public ObserverPattern::Subject, public System
        {
        public:
            WindowController(std::string name);

            uint64_t createWindow(sf::VideoMode videoMode, const std::string &title,
                                  sf::Uint32 style = sf::Style::Default,
                                  const sf::ContextSettings &settings = sf::ContextSettings());
            Window *getWindow(uint64_t wid) const;
            bool deleteWindow(uint64_t wid);

            uint64_t openNumber();

            GLenum activateWindow(uint64_t wid);

            void pollEvents();

            ~WindowController();

        private:
            void pollWindow(Window *window);
            void handleEvent(sf::Event evn, sf::RenderWindow &window);

            std::map<uint64_t, Window*> windows;
            uint64_t lwid;
        };
    }
}

#endif //THE_WORLD_WINDOWCONTROLLER_HPP
