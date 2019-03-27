#include "pch.h"
#include "HasPtr.h"

int main()
{
    std::string str("hello world");
    HasPtr p1(str);
    HasPtr p2 = p1;

    return 0;
}
