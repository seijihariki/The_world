//
// Created by seijihariki on 19/12/2016.
//

#include "GraphicsSystem.hpp"

bool TheWorldEngine::Systems::DrawableObject::loadFromResource(ResourceSystem &resources,
                                                               uint64_t rid)
{
    return false;
}

void TheWorldEngine::Systems::DrawableObject::setPosition(sf::Vector2f position)
{
    this->position = position;
}

TheWorldEngine::Systems::GraphicsSystem::GraphicsSystem(std::string name) : ThreadedSystem(name)
{

}

bool TheWorldEngine::Systems::GraphicsSystem::toExecute()
{
    return false;
}