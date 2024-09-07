#pragma once

#include <cstddef>
#include <ostream>

namespace PixL
{
    class String
    {
    public:
        // Constructors
        explicit String( const char* str );
        // Copy Constructor/Assignment
        String( const String& str );
        String& operator=( const String& rhs );
        String& operator=( const char* rhs );
        ~String();

        char* GetCStr() const;
        size_t GetLength() const;
        // Operator Overloads
        char operator[]( size_t index ) const;
        String operator+( const char* str ) const;
        String operator+( const String& str ) const;
        void operator+=( const String& str );
        void operator+=( const char* str );
        bool operator==( const String& rhs ) const;
        bool operator!=( const String& rhs ) const;
    private:
        char* m_string;
        size_t m_length;
    };
}

std::ostream& operator<<( std::ostream& stream, const PixL::String& str );