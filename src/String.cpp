#include <cstring>
#include <iostream>
#include "String.h"

PixL::String::String( const char *str ) {
    m_length = strlen( str );
    m_string = new char[ m_length + 1 ];
    strcpy( m_string, str );

    m_string[ m_length ] = '\0';
}

PixL::String::String( const String &str ) {
    m_length = str.m_length;
    m_string = new char[ m_length + 1 ];
    strcpy( m_string, str.m_string );

    m_string[ m_length ] = '\0';
}

PixL::String &PixL::String::operator=( const String &rhs ) {
    if ( rhs == *this ) return *this;
    m_length = rhs.m_length;
    m_string = new char[ m_length + 1 ];
    strcpy( m_string, rhs.m_string );

    m_string[ m_length ] = '\0';
    return *this;
}

PixL::String &PixL::String::operator=( const char *rhs ) {
    if ( rhs == m_string ) return *this;
    m_length = strlen( rhs );
    m_string = new char[ m_length + 1 ];
    strcpy( m_string, rhs );

    m_string[ m_length ] = '\0';
    return *this;
}

PixL::String::~String() { delete[] m_string; }

char *PixL::String::GetCStr() const { return m_string; }
size_t PixL::String::GetLength() const { return m_length; }

char PixL::String::operator[]( const size_t index ) const {
    if ( index >= m_length ) return 0;
    return m_string[ index ];
}

// Operator Overloads
void PixL::String::operator+=( const String &str ) {
    m_length += str.m_length;
    strcat( m_string, str.m_string );
}

void PixL::String::operator+=( const char *str ) {
    m_length += strlen( str );
    strcat( m_string, str );
}

PixL::String PixL::String::operator+( const char *str ) const { return String( { strcat( m_string, str ) } ); }

PixL::String PixL::String::operator+( const String &str ) const {
    return String( { strcat( m_string, str.m_string ) } );
}

std::ostream &operator<<( std::ostream &stream, const PixL::String &str ) {
    stream << str.GetCStr();
    return stream;
}

bool PixL::String::operator==( const String &rhs ) const { return ( m_string == rhs.m_string ); }

bool PixL::String::operator!=( const String &rhs ) const { return ( m_string != rhs.m_string ); }
