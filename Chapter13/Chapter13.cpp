#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" // a class which deleted its destructor
int main()
{
    //  complier will thrown error message:
    //  1) attempting to reference a deleted function
    //  2) cannot be referenced -- it is a deleted function
    //NoDtor nd;  //  error: NoDtor destructor is deleted
    NoDtor* p = new NoDtor();   // ok: but we can't delete p
    //delete p;   //  error: NoDtor destructor is deleted

    return 0;
}
