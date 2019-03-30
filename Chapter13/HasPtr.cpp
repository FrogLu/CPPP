#include "pch.h"
#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    //auto newptr = std::make_shared<std::string>(*rhs.ps);
    auto newptr = new std::string(*rhs.ps);
    delete ps;  //  destory origin string
    ps = newptr;    // point to a new string
    //ps.reset(newptr);
    i = rhs.i;
    std::cout << "operator=(const HasPtr& rhs)" << std::endl;

    return *this;
}

HasPtr& HasPtr::operator=(const std::string& rhs)
{
    *ps = rhs;

    return *this;
}

std::string& HasPtr::operator*()
{
    return *ps;
}

HasPtr::~HasPtr()
{
    if (-- * use == 0) {
        delete ps;
        delete use;
    }
    std::cout << "~HasPtr()" << std::endl;
    //delete ps;
}
