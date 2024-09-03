#include "String.h"

PixL::String::String( const char* string )
{
    m_length = strlen( string );
    m_data = new char[m_length + 1];
    strcpy( m_data, string );
    m_data[m_length] = 0;
}
PixL::String::String( const PixL::String& rhs )
{
    m_length = rhs.GetLength();
    m_data = new char[m_length + 1];
    strcpy( m_data, rhs.GetCStr() );
    m_data[m_length] = 0;
}
PixL::String& PixL::String::operator = ( const String& rhs )
{
    String str( rhs );
    return str;
}
PixL::String::~String()
{
    delete[] m_data;
}
char PixL::String::at( size_t index ) const
{
    if ( index > m_length + 1 ) return 0;
    return m_data[index];
}
char* PixL::String::GetCStr() const
{
    return m_data;
}
size_t PixL::String::GetLength() const
{
    return m_length;
}

PixL::String PixL::String::operator + ( const char* rhs ) const
{
    size_t length = m_length + strlen( rhs );
    char cstr[length + 1];
    for ( int i = 0; i < m_length; i++ )
    {
        cstr[i] = m_data[i];
    }
    for ( int j = m_length; j < length + 1; j++ )
    {
        cstr[j] = rhs[j - m_length];
    }
    String str(cstr);
    return str;
}
PixL::String& PixL::String::operator += ( const char* rhs )
{
    char buffer[m_length];
    size_t bufferLength = m_length;
    for ( int i = 0; i < m_length; i++ )
    {
        buffer[i] = m_data[i];
    }

    m_length += strlen( rhs );
    m_data = new char[m_length + 1];

    for ( int i = 0; i < bufferLength; i++ )
    {
        m_data[i] = buffer[i];
    }
    for ( int j = bufferLength; j < m_length; j++ )
    {
        m_data[j] = rhs[j - bufferLength];
    }

    m_data[m_length] = 0;
    return *this;
}
PixL::String PixL::String::operator + ( const PixL::String& rhs ) const
{
    size_t length = m_length + rhs.GetLength();
    char cstr[length + 1];
    for ( int i = 0; i < m_length; i++ )
    {
        cstr[i] = m_data[i];
    }
    for ( int j = m_length; j < length + 1; j++ )
    {
        cstr[j] = rhs.at( j - m_length );
    }
    String str(cstr);
    return str;
}
PixL::String& PixL::String::operator += ( const String& rhs )
{
    char buffer[m_length];
    size_t bufferLength = m_length;
    for ( int i = 0; i < m_length; i++ )
    {
        buffer[i] = m_data[i];
    }

    m_length += rhs.GetLength();
    m_data = new char[m_length + 1];

    for ( int i = 0; i < bufferLength; i++ )
    {
        m_data[i] = buffer[i];
    }
    for ( int j = bufferLength; j < m_length; j++ )
    {
        m_data[j] = rhs.at( j - bufferLength );
    }

    m_data[m_length] = 0;
    return *this;
}
std::ostream& operator << ( std::ostream& stream, const PixL::String& string )
{
    stream << string.GetCStr();
    return stream;
} 