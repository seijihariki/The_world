//
// Created by seijihariki on 18/12/2016.
//

#include <stdio.h>
#include "Logger.hpp"

void ::TheWorldEngine::Logger::log_custom(FILE *print_to, char type_id, std::string at, std::string message, ...)
{
    va_list args;
    va_start (args, message);
    fprintf (print_to, "[%c] %s: ", type_id, at.c_str());
    vfprintf (print_to, message.c_str(), args);
    fprintf (print_to, "\n");
    va_end (args);
}

void
::TheWorldEngine::Logger::v_log_custom(FILE *print_to, char type_id, std::string at, std::string message, va_list args)
{
    fprintf (print_to, "[%c] %s: ", type_id, at.c_str());
    vfprintf (print_to, message.c_str(), args);
    fprintf (print_to, "\n");
}

void ::TheWorldEngine::Logger::log_d(std::string at, std::string message, ...)
{
    va_list args;
    va_start (args, message);
    v_log_custom(stdout, 'D', at, message, args);
    va_end (args);
}

void ::TheWorldEngine::Logger::log_e(std::string at, std::string message, ...)
{
    va_list args;
    va_start (args, message);
    v_log_custom(stderr, 'E', at, message, args);
    va_end (args);
}

void ::TheWorldEngine::Logger::log_i(std::string at, std::string message, ...)
{
    va_list args;
    va_start (args, message);
    v_log_custom(stdout, 'I', at, message, args);
    va_end (args);
}

void ::TheWorldEngine::Logger::v_log_d(std::string at, std::string message, va_list args)
{
    v_log_custom(stdout, 'D', at, message, args);
}

void ::TheWorldEngine::Logger::v_log_e(std::string at, std::string message, va_list args)
{
    v_log_custom(stderr, 'E', at, message, args);
}

void ::TheWorldEngine::Logger::v_log_i(std::string at, std::string message, va_list args)
{
    v_log_custom(stdout, 'I', at, message, args);
}
