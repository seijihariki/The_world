//
// Created by seijihariki on 20/12/2016.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceSystem.hpp"
#include "../Base/Logger.hpp"

void *::TheWorldEngine::Systems::ResourceFunctions::loadTexture(std::string &filename)
{
    sf::Texture *texture;
    try {
        texture = new sf::Texture();
        if (!texture->loadFromFile(filename))
        {
            delete texture;
            Logger::log_e(name, "Failed loading texture for %s", filename);
            return 0;
        }
    } catch (std::bad_alloc ba)
    {
        Logger::log_e(name, "Failed to allocate texture for %s", filename);
        return 0;
    }
    return texture;
}

//TODO implement mesh and Drawable loading

void *::TheWorldEngine::Systems::ResourceFunctions::loadMesh(std::string &filename)
{
    return nullptr;
}

void *::TheWorldEngine::Systems::ResourceFunctions::loadDrawable(std::string &filename)
{
    return nullptr;
}

void *::TheWorldEngine::Systems::ResourceFunctions::loadSoundBuffer(std::string &filename)
{
    sf::SoundBuffer *soundBuffer;
    try {
        soundBuffer = new sf::SoundBuffer();
        if (!soundBuffer->loadFromFile(filename))
        {
            delete soundBuffer;
            Logger::log_e(name, "Failed loading sound for %s", filename);
            return 0;
        }
    } catch (std::bad_alloc ba)
    {
        Logger::log_e(name, "Failed to allocate sound for %s", filename);
        return 0;
    }
    return soundBuffer;
}

void *::TheWorldEngine::Systems::ResourceFunctions::loadMusic(std::string &filename)
{
    sf::Music *music;
    try {
        music = new sf::Music();
        if (!music->openFromFile(filename))
        {
            delete music;
            Logger::log_e(name, "Failed loading sound for %s", filename);
            return 0;
        }
    } catch (std::bad_alloc ba)
    {
        Logger::log_e(name, "Failed to allocate sound for %s", filename);
        return 0;
    }
    return music;
}

TheWorldEngine::Systems::Resource::Resource(uint64_t rid, ResourceType type,
                                            void *resource) : rid(rid), type(type), resource(resource)
{
}

TheWorldEngine::Systems::ResourceType TheWorldEngine::Systems::Resource::getType() const
{
    return type;
}

void *TheWorldEngine::Systems::Resource::getResource() const
{
    return resource;
}

TheWorldEngine::Systems::ResourceSystem::ResourceSystem(std::string name) : System(name), lrid(1)
{
}

//TODO implement resource description file

bool TheWorldEngine::Systems::ResourceSystem::loadResources(std::string filename)
{
    return false;
}

uint64_t TheWorldEngine::Systems::ResourceSystem::loadResourceFromFile(std::string filename, ResourceType type)
{
    Resource *res = nullptr;
    void *tmp = nullptr;

    std::string r_type = "none";

    switch (type)
    {
        case TEXTURE:
            tmp = ResourceFunctions::loadTexture(filename);
            break;
        case MESH:
            tmp = ResourceFunctions::loadMesh(filename);
            break;
        case DRAWABLE:
            tmp = ResourceFunctions::loadDrawable(filename);
            break;
        case SOUNDBUFFER:
            tmp = ResourceFunctions::loadSoundBuffer(filename);
            break;
        case MUSIC:
            tmp = ResourceFunctions::loadMusic(filename);
            break;
        default:
            l_error("Unknown resource type.");
            return 0;
    }

    if (tmp == nullptr)
    {
        l_error("Error loading %s resource %s", r_type, filename);
        return 0;
    }

    try {
        res = new Resource(lrid, type, tmp);
    } catch (std::bad_alloc& ba)
    {
        l_error("Failed to allocate %s resource for %s", r_type, filename);
        return 0;
    }

    auto insertion_result = resources.insert({lrid, res});

    if(!insertion_result.second)
    {
        l_error("Same id resource already existed!! rid: %d", lrid);
        delete res;
        return 0;
    }

    return lrid++;
}

TheWorldEngine::Systems::Resource *TheWorldEngine::Systems::ResourceSystem::getResource(uint64_t rid) const
{
    auto search_result = resources.find(rid);
    if (search_result == resources.end())
        return 0;
    return search_result->second;
}

bool TheWorldEngine::Systems::ResourceSystem::deleteWindow(uint64_t rid)
{
    return resources.erase(rid) != 0;
}

TheWorldEngine::Systems::ResourceSystem::~ResourceSystem()
{
    for (auto resource : resources)
        delete resource.second;
}
