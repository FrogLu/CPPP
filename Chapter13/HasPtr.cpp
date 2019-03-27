#include "pch.h"
#include "HasPtr.h"

HasPtr::HasPtr(const HasPtr& ptr)
{
    ps = new std::string(*ptr.ps);
    i = ptr.i;
}

HasPtr& HasPtr::operator=(const HasPtr& ptr)
{
    ps = new std::string(*ptr.ps);
    i = ptr.i;
}
