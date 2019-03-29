#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"

int main()
{
    Employee ep1, ep2("FrogLu");
    Employee ep3 = ep2;

    return 0;
}
