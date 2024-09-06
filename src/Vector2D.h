#pragma once

#include <iostream>

namespace PixL
{
    class Vector2D
    {
    public:
        // Static Factory Methods
        static Vector2D Zero();
        static Vector2D One();
        static Vector2D Right();
        static Vector2D Up();

        // Static Utility Methods
        static float Distance( const Vector2D& v1, const Vector2D& v2 );
    public:
        float x, y;

        // Constructor
        Vector2D();
        Vector2D( float x, float y );

        // Vector Operation Methods
        Vector2D Normalized() const;
        float SqrMagnitude() const;
        float Magnitude() const;

        //---------- Operator Overloads ----------
        // Unary Arithmetic
        Vector2D operator+() const;
        Vector2D operator-() const;
        // Binary Arithmetic
        Vector2D operator+( const Vector2D& rhs ) const;
        Vector2D operator-( const Vector2D& rhs ) const;
        Vector2D operator*( const Vector2D& rhs ) const;
        Vector2D operator/( const Vector2D& rhs ) const;

        Vector2D operator*( const float& rhs ) const;
        Vector2D operator/( const float& rhs ) const;
        // Compound Assignment
        Vector2D& operator+=( const Vector2D& rhs );
        Vector2D& operator-=( const Vector2D& rhs );
        Vector2D& operator*=( const Vector2D& rhs );
        Vector2D& operator/=( const Vector2D& rhs );

        Vector2D& operator*=( const float& rhs );
        Vector2D& operator/=( const float& rhs );

        // Comparison
        bool operator==( const Vector2D& rhs ) const;
        bool operator!=( const Vector2D& rhs ) const;
    };

}
std::ostream& operator<<( std::ostream& stream, const PixL::Vector2D& vector );