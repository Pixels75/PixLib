#pragma once

#include <chrono>
#include "List.h"

namespace PixL {
    class Profiler;
    class Timer;

    class Profiler {
    public:
        static void StartTimer( const char *name );

        static void EndTimer( const char *name );

    private:
        static List<Timer *> m_timers;

        static bool CheckIfNameExists( const char *name );
    };

    class Timer {
    public:
        const char *name;

        explicit Timer( const char *name );

        ~Timer();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_timerStart;
        std::chrono::time_point<std::chrono::high_resolution_clock> m_timerEnd;
        long double m_duration;
    };
}
