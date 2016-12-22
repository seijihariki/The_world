#include <iostream>

#include <SFML/Graphics.hpp>

#include "Systems/WindowController.hpp"
#include "Systems/ResourceSystem.hpp"

int main(int argc, char* argv[])
{
    TheWorldEngine::WindowController::WindowController window_controller("WindowController");
    TheWorldEngine::Systems::ResourceSystem resource_manager("ResourceManager");

    uint64_t shader1 = resource_manager.loadResourceFromFile("res/shader1", TheWorldEngine::Systems::ResourceType::SHADER);

    uint64_t window1 = window_controller.createWindow({800, 600}, "Window1", sf::Style::Default);

    sf::RenderWindow &window = window_controller.getWindow(window1)->getWindowReference();

    while (window_controller.openNumber())
        window_controller.pollEvents(); // Events must be handled at same thread that created window

    return 0;
}
