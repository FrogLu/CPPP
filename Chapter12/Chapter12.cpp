#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    StrBlob cSB = { "hello","world" };
    for (auto it = cSB.begin(); !eq(it, cSB.end()); it.incr()) {
        std::cout << it.deref() << std::endl;
    }
    return 0;
}