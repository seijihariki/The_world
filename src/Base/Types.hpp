//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_TYPES_HPP
#define THE_WORLD_TYPES_HPP

#include <SFML/Graphics/Glsl.hpp>
#include <glm/detail/type_mat.hpp>

namespace TheWorldEngine
{
    typedef unsigned char byte;

    // Some useful conversion functions
    sf::Glsl::Mat4 toSFML(glm::mat4 &matrix);
}

#endif //THE_WORLD_TYPES_HPP
