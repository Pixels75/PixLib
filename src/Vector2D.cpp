#include <cmath>
#include "Vector2D.h"

PixL::Vector2D PixL::Vector2D::Zero()
{
    return { 0.0f, 0.0f };
}

PixL::Vector2D PixL::Vector2D::One()
{
    return { 1.0f, 1.0f };
}

PixL::Vector2D PixL::Vector2D::Right()
{
    return { 1.0f, 0.0f };
}

PixL::Vector2D PixL::Vector2D::Up()
{
    return { 0.0f, 1.0f };
}

float PixL::Vector2D::Distance( const Vector2D& v1, const Vector2D& v2 )
{
    return ( v1 - v2 ).Magnitude();
}

PixL::Vector2D::Vector2D( float x, float y )
    :
    x( x ),
    y( y )
{}



PixL::Vector2D PixL::Vector2D::Normalized() const
{
    return { x / Magnitude(), y / Magnitude() };
}

float PixL::Vector2D::SqrMagnitude() const
{
    return static_cast<float>( pow( x, 2 ) + pow( y, 2 ) );
}

float PixL::Vector2D::Magnitude() const
{
    return static_cast<float>( sqrt( pow( x, 2 ) + pow( y, 2  ) ) );
}

//---------- Operation Overloads ----------
// Unary Arithmetic
PixL::Vector2D PixL::Vector2D::operator+() const
{
    return *this;
}
PixL::Vector2D PixL::Vector2D::operator-() const
{
    return { -x, -y };
}
// Binary Arithmetic
PixL::Vector2D PixL::Vector2D::operator+( const Vector2D& rhs ) const
{
    return { x + rhs.x, y + rhs.y };
}
PixL::Vector2D PixL::Vector2D::operator-( const Vector2D& rhs ) const
{
    return { x - rhs.x, y - rhs.y };
}
PixL::Vector2D PixL::Vector2D::operator*( const Vector2D& rhs ) const
{
    return { x * rhs.x, y * rhs.y };
}
PixL::Vector2D PixL::Vector2D::operator/( const Vector2D& rhs ) const
{
    return { x / rhs.x, y / rhs.y };
}

PixL::Vector2D PixL::Vector2D::operator*( const float& rhs ) const
{
    return { x * rhs, y * rhs };
}
PixL::Vector2D PixL::Vector2D::operator/( const float& rhs ) const
{
    return { x / rhs, y / rhs };
}

PixL::Vector2D& PixL::Vector2D::operator+=( const Vector2D& rhs )
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}
PixL::Vector2D& PixL::Vector2D::operator-=( const Vector2D& rhs )
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}
PixL::Vector2D& PixL::Vector2D::operator*=( const Vector2D& rhs )
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}
PixL::Vector2D& PixL::Vector2D::operator/=( const Vector2D& rhs )
{
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

PixL::Vector2D& PixL::Vector2D::operator*=( const float& rhs )
{
    x *= rhs;
    y *= rhs;
    return *this;
}
PixL::Vector2D& PixL::Vector2D::operator/=( const float& rhs )
{
    x /= rhs;
    y /= rhs;
    return *this;
}

// Comparison
bool PixL::Vector2D::operator==( const Vector2D& rhs ) const
{
    return ( x == rhs.x && y == rhs.y );
}
bool PixL::Vector2D::operator!=( const Vector2D& rhs ) const
{
    return !( x == rhs.x && y == rhs.y );
}

std::ostream& operator<<( std::ostream& stream, const PixL::Vector2D& vector )
{
    stream << "( " << vector.x << ", " << vector.y << " )";
    return stream;
}