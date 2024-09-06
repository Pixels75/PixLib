#pragma once

#include <ostream>

namespace PixL
{
    template<typename T>
    class List
    {
    public:
        // Constructors
        explicit List() = default;
        explicit List( size_t initSize )
        {
            m_len = initSize;
            m_list = new T[ m_cap ];
        }
        // Copy Constructor/Assignment
        List( List& rhs )
        {
            m_len = rhs.m_len;
            delete[] m_list;
            m_list = new T[ m_len ];
            for ( size_t i = 0; i < m_len; i++ )
            {
                m_list[ i ] = rhs.m_list[ i ];
            }
        }
        List& operator=( List& rhs )
        {
            if ( rhs == *this ) return *this;

            m_cap = rhs.m_cap;
            m_len = rhs.m_len;
            delete[] m_list;
            m_list = new T[ m_cap ];
            for ( size_t i = 0; i < m_cap; i++ )
            {
                m_list[ i ] = rhs.m_list[ i ];
            }
            return *this;
        }
        // Operator Overloads
        T& operator[]( size_t index )
        {
            return m_list[ index ];
        }
        List& operator+=( const T& element )
        {
            m_len++;
            if ( m_len >= m_cap ) m_cap *= 2;
            T* newList = new T[ m_cap ];
            for ( size_t i = 0; i < m_len - 1; i++ )
            {
                newList[ i ] = m_list[ i ];
            }
            for ( size_t i = m_len; i < m_cap; i++ )
            {
                newList[ i ] = T();
            }
            newList[ m_len - 1 ] = element;
            delete[] m_list;
            m_list = newList;
            return *this;
        }
    private:
        T* m_list = nullptr;
        size_t m_len = 0;
        size_t m_cap = 2;
    };
}