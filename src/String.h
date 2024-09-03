#pragma once

#include <iostream>
#include <stddef.h>
#include <cstring>

namespace PixL
{
    class String
    {
    public:
        String( const char* string );
        String( const String& rhs );
        String& operator = ( const String& rhs );
        ~String();

        char at( size_t index ) const;
        char* GetCStr() const;
        size_t GetLength() const;

        String operator + ( const char* rhs ) const;
        String& operator += ( const char* rhs );
        String operator + ( const String& rhs ) const;
        String& operator += ( const String& rhs );
    private:
        char* m_data;
        size_t m_length;
    };
}

std::ostream& operator << ( std::ostream& stream, const PixL::String& string );