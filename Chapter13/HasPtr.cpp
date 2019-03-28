#include "pch.h"
#include "HasPtr.h"

HasPtr::HasPtr(const HasPtr& ptr)
{
    ps = new std::string(*ptr.ps);
    i = ptr.i;
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newptr = new std::string(*rhs.ps);
    delete ps;  //  destory origin string
    ps = newptr;    // point to a new string
    i = rhs.i;

    return *this;
}
