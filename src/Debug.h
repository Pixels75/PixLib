#pragma once

#include <iostream>

enum LogLevel { Nothing = 0, Error, Warning, Message };

namespace PixL
{
    class Debug
    {
    public:
        static LogLevel logLevel;
    public:

        template<typename T>
        static void LogMsg( const T& message )
        {
            if ( logLevel < Message ) return;
            std::cout << "(m) - " << message << '\n';
        }

        template<typename T>
        static void LogWarn( const T& warning )
        {
            if ( logLevel < Warning ) return;
            std::cout << "(w) - " << warning << '\n';
        }

        template<typename T>
        static void LogErr( const T& error )
        {
            if ( logLevel < Error ) return;
            std::cout << "(e) - " << error << '\n';
        }
    };
}