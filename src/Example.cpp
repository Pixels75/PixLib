#include "Debug.h"
#include "Profiler.h"
#include "String.h"
#include "Vec2.h"
#include "Array.h"
#include "List.h"

using namespace PixL;

int main() {
    Profiler::StartTimer( "Vector2" );
    // Vector2D
    Vec2 vec = { 3, -2 };
    Debug::LogMsg( vec );
    Profiler::EndTimer( "Vector2" );
    Profiler::StartTimer( "Array" );
    // Array
    Array<int, 4> arr( ( const int[ ] ){ 1, 3, 5, 7 } );
    for ( int i = 0; i < arr.GetLength(); i++ ) { Debug::LogMsg( arr[ i ] ); }
    Profiler::EndTimer( "Array" );
    Profiler::StartTimer( "List" );
    // List
    List<int> list;
    for ( int i = 1; i <= 10; i++ ) { list += i; }
    Debug::LogMsg( "List -" );
    for ( int i = 0; i < 10; i++ ) { Debug::LogMsg( list[ i ] ); }
    Profiler::EndTimer( "List" );
    Profiler::StartTimer( "String" );
    // String
    String str1( "Message " );
    String str2( "Printed" );
    str2 += "!";
    Debug::LogMsg( str1 + str2 );
    Profiler::EndTimer( "String" );
}
