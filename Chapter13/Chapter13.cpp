#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"
#include "StrBlob.h"

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = { "hello","world","FrogLu" };
        b1 = b2;
        b2.push_back("about");
        std::cout << "b2's size is: " << b2.size() << std::endl;
        std::cout << "b2's first and end element: " << b2.front() << " " << b2.back() << std::endl;
    }
    std::cout << "b1's size is: " << b1.size() << std::endl;
    std::cout << "b1's first and end element: " << b1.front() << " " << b1.back() << std::endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    std::cout << "b3's size is: " << b3.size() << std::endl;
    std::cout << "b3's first and end element: " << b3.front() << " " << b3.back() << std::endl;

    std::cout << "all element of b1: " << std::endl;
    for (auto iter = b1.begin(); !eq(iter, b1.end()); iter.incr()) {
        std::cout<<iter.deref()<<std::endl;
    }

    return 0;
}
