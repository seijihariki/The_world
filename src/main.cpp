#include <iostream>

#include <GL/glew.h>

#include <SFML/Graphics.hpp>

#include "Systems/WindowController.hpp"

void handle(sf::Event event, sf::Window &window);

int main(int argc, char* argv[])
{
    TheWorldEngine::WindowController::WindowController window_controller("WindowController");

    uint64_t wid = window_controller.createWindow({800, 600}, "Title", sf::Style::Default);
    sf::RenderWindow &window = window_controller.getWindow(wid)->getWindowReference();

    window_controller.activateWindow(wid);

    sf::Shader shader;

    if (!shader.loadFromFile("res/vertex.vert", "res/fragment.frag"))
    {
        std::cerr << "FAILED LOADING SHADERS!!";
    }

    float points[] = {
            0.0f,  0.5f,  0.0f,
            0.5f, -0.5f,  0.0f,
            -0.5f, -0.5f,  0.0f
    };

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    // wipe the drawing surface clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    sf::Shader::bind(&shader);
    glBindVertexArray(vao);
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, 3);

    window.display();

    while (window.isOpen())
        window_controller.pollEvents(); // Events must be handled at same thread that created window

    return 0;
}
