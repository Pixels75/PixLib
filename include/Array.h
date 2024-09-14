#pragma once

namespace PixL {
    template <typename T, size_t S>
    class Array {
    public:
        // Constructor
        explicit Array( const T array[ S ] ) { for ( size_t i = 0; i < S; i++ ) { m_array[ i ] = array[ i ]; } }

        constexpr size_t GetLength() const { return S; }
        // Operator Overloads
        T &operator[]( size_t index ) { return m_array[ index ]; }

    private:
        T m_array[ S ];
    };
}
