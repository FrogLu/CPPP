#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"

int main()
{
    HasPtr hp1("hello"), hp2(hp1);
    HasPtr hp3 = hp2;

    return 0;
}
