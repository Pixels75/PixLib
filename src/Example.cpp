#include "Debug.h"
#include "String.h"
#include "Vector2D.h"

using namespace PixL;

int main()
{
    Vector2D vec = { 3, -2 };
    std::cout << vec << '\n';

    String str1 = "Message ";
    String str2 = "Printed!";

    Debug::LogMsg( ( str1 + str2 ).GetCStr() );
}