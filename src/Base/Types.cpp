#include "Types.hpp"
//
// Created by seijihariki on 22/12/2016.
//
#include <glm/gtc/type_ptr.hpp>

sf::Glsl::Mat4 TheWorldEngine::toSFML(glm::mat4 &matrix){
    sf::Glsl::Mat4 ret(glm::value_ptr(matrix));
    return ret;
}
