#include "Debug.h"
#include "Vec2.h"
#include "String.h"

using namespace PixL;

int main()
{
    String str = "Hello, World!";
    str += "\nHi!";
    std::cout << str + "\nBye!"<< '\n';
}