#pragma once

#include <iostream>
#include "String.h"
#include "Vec2.h"

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
            std::cout << "[MSG] - " << message << '\n';
        }

        template<typename T>
        static void LogWarn( const T& warning )
        {
            if ( logLevel < Warning ) return;
            std::cout << "[WARN] - " << warning << '\n';
        }

        template<typename T>
        static void LogErr( const T& error )
        {
            if ( logLevel < Error ) return;
            std::cout << "[ERR] - " << error << '\n';
        }
    };
}