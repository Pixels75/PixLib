#pragma once

#include <iostream>

namespace PixL {
    class Vec2 {
    public:
        // Static Factory Methods
        static Vec2 Zero();

        static Vec2 One();

        static Vec2 Right();

        static Vec2 Up();

        // Static Utility Methods
        static float Distance( const Vec2 &v1, const Vec2 &v2 );

    public:
        float x, y;

        // Constructor
        Vec2();

        Vec2( float x, float y );

        // Vector Operation Methods
        Vec2 Normalized() const;

        float SqrMagnitude() const;

        float Magnitude() const;

        //---------- Operator Overloads ----------
        // Unary Arithmetic
        Vec2 operator+() const;

        Vec2 operator-() const;

        // Binary Arithmetic
        Vec2 operator+( const Vec2 &rhs ) const;

        Vec2 operator-( const Vec2 &rhs ) const;

        Vec2 operator*( const Vec2 &rhs ) const;

        Vec2 operator/( const Vec2 &rhs ) const;

        Vec2 operator*( const float &rhs ) const;

        Vec2 operator/( const float &rhs ) const;

        // Compound Assignment
        Vec2 &operator+=( const Vec2 &rhs );

        Vec2 &operator-=( const Vec2 &rhs );

        Vec2 &operator*=( const Vec2 &rhs );

        Vec2 &operator/=( const Vec2 &rhs );

        Vec2 &operator*=( const float &rhs );

        Vec2 &operator/=( const float &rhs );

        // Comparison
        bool operator==( const Vec2 &rhs ) const;

        bool operator!=( const Vec2 &rhs ) const;
    };
}

std::ostream &operator<<( std::ostream &stream, const PixL::Vec2 &vector );
