//
// Created by seijihariki on 20/12/2016.
//

#ifndef THE_WORLD_RESOURCESYSTEM_HPP
#define THE_WORLD_RESOURCESYSTEM_HPP

#include <map>
#include "../Base/System.hpp"

namespace TheWorldEngine
{
    namespace Systems
    {
        namespace ResourceFunctions
        {
            const std::string name("ResourceFunctions");
            void *loadTexture(std::string &filename);
            void *loadMesh(std::string &filename);
            void *loadDrawable(std::string &filename);
            void *loadSoundBuffer(std::string &filename);
            void *loadMusic(std::string &filename);
        }

        enum ResourceType
        {
            TEXTURE,
            MESH,
            DRAWABLE,
            SOUNDBUFFER,
            MUSIC
        };

        class Resource
        {
        public:
            Resource(uint64_t rid, ResourceType type, void *resource);

            ResourceType getType() const;
            void *getResource() const;

        private:
            const uint64_t rid;
            const ResourceType type;
            void *resource;
        };

        class ResourceSystem : public System
        {
        public:
            ResourceSystem(std::string name);

            bool loadResources(std::string filename);
            uint64_t loadResourceFromFile(std::string filename, ResourceType type);

            Resource *getResource(uint64_t rid) const;
            bool deleteWindow(uint64_t rid);

            ~ResourceSystem();

        private:
            std::map<uint64_t, Resource*> resources;
            uint64_t lrid;
        };
    }
}


#endif //THE_WORLD_RESOURCESYSTEM_HPP
