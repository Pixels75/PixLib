#include <cmath>
#include "Vec2.h"

PixL::Vec2 PixL::Vec2::Zero() { return { 0.0f, 0.0f }; }

PixL::Vec2 PixL::Vec2::One() { return { 1.0f, 1.0f }; }

PixL::Vec2 PixL::Vec2::Right() { return { 1.0f, 0.0f }; }

PixL::Vec2 PixL::Vec2::Up() { return { 0.0f, 1.0f }; }

float PixL::Vec2::Distance( const Vec2 &v1, const Vec2 &v2 ) { return ( v1 - v2 ).Magnitude(); }

PixL::Vec2::Vec2()
    : x( 0 ),
      y( 0 ) {}

PixL::Vec2::Vec2( float x, float y )
    : x( x ),
      y( y ) {}


PixL::Vec2 PixL::Vec2::Normalized() const { return { x / Magnitude(), y / Magnitude() }; }

float PixL::Vec2::SqrMagnitude() const { return static_cast<float>( pow( x, 2 ) + pow( y, 2 ) ); }

float PixL::Vec2::Magnitude() const { return static_cast<float>( sqrt( pow( x, 2 ) + pow( y, 2 ) ) ); }

//---------- Operation Overloads ----------
// Unary Arithmetic
PixL::Vec2 PixL::Vec2::operator+() const { return *this; }
PixL::Vec2 PixL::Vec2::operator-() const { return { -x, -y }; }
// Binary Arithmetic
PixL::Vec2 PixL::Vec2::operator+( const Vec2 &rhs ) const { return { x + rhs.x, y + rhs.y }; }
PixL::Vec2 PixL::Vec2::operator-( const Vec2 &rhs ) const { return { x - rhs.x, y - rhs.y }; }
PixL::Vec2 PixL::Vec2::operator*( const Vec2 &rhs ) const { return { x * rhs.x, y * rhs.y }; }
PixL::Vec2 PixL::Vec2::operator/( const Vec2 &rhs ) const { return { x / rhs.x, y / rhs.y }; }

PixL::Vec2 PixL::Vec2::operator*( const float &rhs ) const { return { x * rhs, y * rhs }; }
PixL::Vec2 PixL::Vec2::operator/( const float &rhs ) const { return { x / rhs, y / rhs }; }

PixL::Vec2 &PixL::Vec2::operator+=( const Vec2 &rhs ) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

PixL::Vec2 &PixL::Vec2::operator-=( const Vec2 &rhs ) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

PixL::Vec2 &PixL::Vec2::operator*=( const Vec2 &rhs ) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

PixL::Vec2 &PixL::Vec2::operator/=( const Vec2 &rhs ) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

PixL::Vec2 &PixL::Vec2::operator*=( const float &rhs ) {
    x *= rhs;
    y *= rhs;
    return *this;
}

PixL::Vec2 &PixL::Vec2::operator/=( const float &rhs ) {
    x /= rhs;
    y /= rhs;
    return *this;
}

// Comparison
bool PixL::Vec2::operator==( const Vec2 &rhs ) const { return ( x == rhs.x && y == rhs.y ); }
bool PixL::Vec2::operator!=( const Vec2 &rhs ) const { return !( x == rhs.x && y == rhs.y ); }

std::ostream &operator<<( std::ostream &stream, const PixL::Vec2 &vector ) {
    stream << "( " << vector.x << ", " << vector.y << " )";
    return stream;
}
