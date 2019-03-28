#include "pch.h"
#include "HasPtr.h"

HasPtr f(HasPtr hp) {
    HasPtr ret = hp;
    
    return ret;
}

int main()
{
    HasPtr hp("some values");
    f(hp);
    HasPtr q(hp);

    return 0;
}
