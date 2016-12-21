//
// Created by seijihariki on 18/12/2016.
//

#ifndef THE_WORLD_LOGGER_HPP
#define THE_WORLD_LOGGER_HPP

#include <string>
#include <cstdarg>

namespace TheWorldEngine
{
    namespace Logger
    {
        void log_custom(FILE *print_to, char type_id, std::string at, std::string message, ...);
        void v_log_custom(FILE *print_to, char type_id, std::string at, std::string message, va_list args);

        void log_d(std::string at, std::string message, ...);
        void log_e(std::string at, std::string message, ...);
        void log_i(std::string at, std::string message, ...);

        void v_log_d(std::string at, std::string message, va_list args);
        void v_log_e(std::string at, std::string message, va_list args);
        void v_log_i(std::string at, std::string message, va_list args);
    }
}

#endif //THE_WORLD_LOGGER_HPP
