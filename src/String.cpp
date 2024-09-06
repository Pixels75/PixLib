#include <cstring>
#include <iostream>
#include "String.h"


PixL::String::String( const char* str )
{
    m_len = strlen( str );
    m_str = new char[ m_len + 1 ];
    strcpy( m_str, str );

    m_str[ m_len ] = '\0';
}

PixL::String::String( const String& str )
{
    m_len = str.m_len;
    m_str = new char[ m_len + 1 ];
    strcpy( m_str, str.m_str );

    m_str[ m_len ] = '\0';
}

PixL::String& PixL::String::operator=( const String& rhs )
{
    if ( rhs == *this ) return *this;
    m_len = rhs.m_len;
    m_str = new char[ m_len + 1 ];
    strcpy( m_str, rhs.m_str );

    m_str[ m_len ] = '\0';
    return *this;
}

PixL::String& PixL::String::operator=( const char* rhs )
{
    if ( rhs == m_str ) return *this;
    m_len = strlen( rhs );
    m_str = new char[ m_len + 1 ];
    strcpy( m_str, rhs );

    m_str[ m_len ] = '\0';
    return *this;
}

PixL::String::~String()
{
    delete[] m_str;
}

char* PixL::String::GetCStr() const
{
    return m_str;
}
size_t PixL::String::GetLength() const
{
    return m_len;
}

char PixL::String::operator[]( size_t index ) const
{
    if ( index >= m_len ) return 0;
    return m_str[ index ];
}

// Operator Overloads
void PixL::String::operator+=( const String& str )
{
    m_len += str.m_len;
    strcat( m_str, str.m_str );
}

void PixL::String::operator+=( const char* str )
{
    m_len += strlen( str );
    strcat( m_str, str );
}

PixL::String PixL::String::operator+( const char* str ) const
{
    return String( { strcat( m_str, str ) } );
}

PixL::String PixL::String::operator+( const String& str ) const
{
    return String( { strcat( m_str, str.m_str ) } );
}

std::ostream& operator<<( std::ostream& stream, const PixL::String& str )
{
    stream << str.GetCStr();
    return stream;
}

bool PixL::String::operator==( const String& rhs ) const
{
    return ( m_str == rhs.m_str );
}

bool PixL::String::operator!=(const String& rhs) const
{
    return ( m_str != rhs.m_str );
}