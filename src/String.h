#pragma once

#include <cstddef>
#include <ostream>

namespace PixL
{
    class String
    {
    public:
        explicit( false ) String( const char* str );
        String( const String& str );
        ~String();

        char* GetCStr() const;
        size_t GetLength() const;
        // Operator Overloads
        char operator[]( size_t index ) const;
        void operator+=( const String& str );
        void operator+=( const char* str );
        String operator+( const char* str ) const;
        String operator+( const String& str ) const;
    private:
        char* m_str;
        size_t m_len;
    };
}

std::ostream& operator<<( std::ostream& stream, const PixL::String& str );