#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);

    return 0;
}
