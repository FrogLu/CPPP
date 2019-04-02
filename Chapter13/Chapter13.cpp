#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"
#include "StrBlob.h"

int main()
{
    HasPtr hp1("hello"), hp2("world");
    std::cout << "Before: " << hp1.get() << " " << hp2.get() << std::endl;
    swap(hp1, hp2);
    std::cout << "After: " << hp1.get() << " " << hp2.get() << std::endl;

    return 0;
}
