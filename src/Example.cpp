#include "Debug.h"
#include "String.h"
#include "Vector2D.h"
#include "Array.h"

using namespace PixL;

int main()
{
    // Vector2D
    Vector2D vec = { 3, -2 };
    Debug::LogMsg( vec );
    // Array
    Array<int, 4> arr( ( const int[] ){ 1, 3, 5, 7 } );
    for ( int i = 0; i < arr.GetLength(); i++ )
    {
        Debug::LogMsg( arr[ i ] );
    }
    // String
    String str1( "Message " );
    String str2( "Printed" );
    str2 += "!";
    Debug::LogMsg( str1 + str2 );
}