//
// Created by seijihariki on 19/12/2016.
//

#ifndef THE_WORLD_GRAPHICS_HPP
#define THE_WORLD_GRAPHICS_HPP

#include <SFML/Window.hpp>
#include "../Base/System.hpp"
#include "ResourceSystem.hpp"

//TODO implement ALL of the graphics system

namespace TheWorldEngine
{
    namespace Systems
    {
        class DrawableObject
        {
        public:
            virtual void draw() = 0;

            bool loadFromResource(ResourceSystem &resources, uint64_t rid);

            void setPosition(sf::Vector2f position);

        private:
            sf::Vector2f position;
        };

        class GraphicsSystem : public ThreadedSystem
        {
        public:
            GraphicsSystem(std::string name);

            bool toExecute();

        private:
        };
    }
}

#endif //THE_WORLD_GRAPHICS_HPP
