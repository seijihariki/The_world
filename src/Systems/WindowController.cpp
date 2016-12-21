//
// Created by seijihariki on 18/12/2016.
//

#include <cstdarg>
#include "WindowController.hpp"

TheWorldEngine::WindowController::Window::Window(uint64_t wid, sf::VideoMode videoMode, const std::string &title,
                                                 sf::Uint32 style,
                                                 const sf::ContextSettings &settings) : wid(wid),
                                                                            window(videoMode, title, style, settings)
{
}

TheWorldEngine::WindowController::WindowController::WindowController(std::string name) : System(name), lwid(1)
{
}

uint64_t TheWorldEngine::WindowController::WindowController::createWindow(sf::VideoMode videoMode,
                                                                          const std::string &title,
                                                                          sf::Uint32 style,
                                                                          const sf::ContextSettings &settings)
{
    auto insertion_result = windows.insert({lwid, new Window(lwid, videoMode, title, style, settings)});

    if (!insertion_result.second)
    {
        l_error("Failed creating window");
        l_error("title: \"%s\"", title.c_str());
        l_error("resolution: %dx%d", videoMode.width, videoMode.height);
        return 0;
    }

    l_info("Created window \"%s\" with id %d", title.c_str(), lwid);
    getWindow(lwid)->getWindowReference().setActive(false);
    l_debug("resolution: %dx%d", videoMode.width, videoMode.height);
    return lwid++;
}

TheWorldEngine::WindowController::Window *
TheWorldEngine::WindowController::WindowController::getWindow(uint64_t wid) const
{
    auto search_result = windows.find(wid);
    if (search_result == windows.end())
        return 0;
    return search_result->second;
}

bool TheWorldEngine::WindowController::WindowController::deleteWindow(uint64_t wid)
{
    return windows.erase(wid) != 0;
}

uint64_t TheWorldEngine::WindowController::WindowController::openNumber()
{
    uint64_t open_windows = 0;
    for (auto window : windows)
    {
        if (window.second->getWindowReference().isOpen())
            open_windows++;
    }
    return open_windows;
}

GLenum TheWorldEngine::WindowController::WindowController::activateWindow(uint64_t wid)
{
    Window *wnd;
    if (!(wnd = getWindow(wid)))
        return (GLenum) -1;
    wnd->getWindowReference().setActive();
    return glewInit();
}

void TheWorldEngine::WindowController::WindowController::pollEvents()
{
    for (auto window : windows)
        pollWindow(window.second);
}

TheWorldEngine::WindowController::WindowController::~WindowController()
{
    for (auto window : windows)
        delete window.second;
}

void TheWorldEngine::WindowController::WindowController::pollWindow(Window *window)
{
    sf::Event evn;
    sf::RenderWindow &wnd = window->getWindowReference();

    while (wnd.pollEvent(evn))
        handleEvent(evn, wnd);
}

void TheWorldEngine::WindowController::WindowController::handleEvent(sf::Event evn, sf::RenderWindow &window)
{
    Event::EventData data;
    data.sfml = evn;
    notify(Event::Event(Event::EventType::SYSTEM_EVENT, data, Event::DataType::SFML));
    switch (evn.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
    }
}