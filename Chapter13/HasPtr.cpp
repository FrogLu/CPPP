#include "pch.h"
#include "HasPtr.h"

HasPtr& HasPtr::operator=(const std::string& rhs)
{
    *ps = rhs;

    return *this;
}

bool HasPtr::operator<(const HasPtr& rhs)
{
    if ((*(this->ps)) < (*(rhs.ps))) {
        return true;
    }
    else {
        return false;
    }
}

std::string& HasPtr::operator*()
{
    return *ps;
}

std::string HasPtr::get()
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

