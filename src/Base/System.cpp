//
// Created by seijihariki on 18/12/2016.
//

#include <cstdarg>
#include "System.hpp"
#include "Logger.hpp"

TheWorldEngine::System::System(std::string name) : name(name)
{
    l_info("Created system %s", name.c_str());
}

void TheWorldEngine::System::l_debug(std::string message, ...)
{
    va_list args;
    va_start (args, message);
    Logger::v_log_d(name, message, args);
    va_end (args);
}

void TheWorldEngine::System::l_error(std::string message, ...)
{
    va_list args;
    va_start (args, message);
    Logger::v_log_e(name, message, args);
    va_end (args);
}

void TheWorldEngine::System::l_info(std::string message, ...)
{
    va_list args;
    va_start (args, message);
    Logger::v_log_i(name, message, args);
    va_end (args);
}

TheWorldEngine::ThreadedSystem::ThreadedSystem(std::string name) : System(name), thread(loop, this)
{
    thread.launch();
}

void TheWorldEngine::ThreadedSystem::startThread()
{
    thread.launch();
}

void TheWorldEngine::ThreadedSystem::stopThread()
{
    thread.terminate();
}

void TheWorldEngine::ThreadedSystem::loop()
{
    while(toExecute());
}