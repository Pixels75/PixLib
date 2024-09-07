#include <iostream>
#include "Profiler.h"

PixL::List<PixL::Timer*> PixL::Profiler::m_timers = PixL::List<PixL::Timer*>();

void PixL::Profiler::StartTimer( const char* name )
{
    if ( CheckIfNameExists( name ) ) ;
    auto timer = new Timer( name );
    m_timers += timer;
}

void PixL::Profiler::EndTimer( const char* name )
{
    for ( size_t i = 0; i < m_timers.GetLength(); i++ )
    {
        if ( m_timers[ i ]->name != name ) continue;
        m_timers.RemoveAt( i );
    }
}

bool PixL::Profiler::CheckIfNameExists(const char* name)
{
    for ( size_t i = 0; i < m_timers.GetLength(); i++ )
    {
        if ( name == m_timers[ i ]->name ) return true;
    }
    return false;
}

PixL::Timer::Timer( const char* name )
    : name( name ),
      m_timerStart( std::chrono::high_resolution_clock::now() )
{}

PixL::Timer::~Timer()
{
    m_timerEnd = std::chrono::high_resolution_clock::now();
    m_duration =  std::chrono::duration_cast<std::chrono::microseconds>( m_timerEnd - m_timerStart ).count();
    std::cout << name << " took " << m_duration << " microseconds" << std::endl;
}
