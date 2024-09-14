#pragma once

namespace PixL {
    template <typename T>
    class List {
    public:
        // Constructors
        explicit List() { m_list = new T[ m_capacity ]; }

        explicit List( const size_t initSize ) {
            m_length = initSize;
            m_list = new T[ m_capacity ];
        }

        // Copy Constructor/Assignment
        List( List &rhs ) {
            m_length = rhs.m_length;
            delete[] m_list;
            m_list = new T[ m_length ];
            for ( size_t i = 0; i < m_length; i++ ) { m_list[ i ] = rhs.m_list[ i ]; }
        }

        List &operator=( List &rhs ) {
            if ( rhs == *this ) return *this;

            m_capacity = rhs.m_capacity;
            m_length = rhs.m_length;
            delete[] m_list;
            m_list = new T[ m_capacity ];
            for ( size_t i = 0; i < m_capacity; i++ ) { m_list[ i ] = rhs.m_list[ i ]; }
            return *this;
        }

        size_t GetLength() const { return m_length; }

        void RemoveAt( size_t index ) {
            if ( index >= m_length ) return;
            delete m_list[ index ];
            for ( size_t i = index; i < m_length - 1; i++ ) { m_list[ i ] = std::move( m_list[ i + 1 ] ); }
            m_length--;
        }

        // Operator Overloads
        T &operator[]( size_t index ) { return m_list[ index ]; }

        List &operator+=( const T &element ) {
            m_length++;
            if ( m_length < m_capacity ) {
                m_list[ m_length - 1 ] = element;
                return *this;
            }
            m_capacity *= 2;
            T *newList = new T[ m_capacity ];
            for ( size_t i = 0; i < m_length - 1; i++ ) { newList[ i ] = m_list[ i ]; }
            newList[ m_length - 1 ] = element;
            delete[] m_list;
            m_list = newList;
            return *this;
        }

    private:
        T *m_list = nullptr;
        size_t m_length = 0;
        size_t m_capacity = 2;
    };
}
