#pragma once
#ifndef _HASPTR_H_
#define _HASPTR_H_

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) :
        ps(new std::string(s)), i(0),use(new std::size_t(1)) {
        std::cout << "HasPtr(const std::string& s = std::string()) called" << std::endl;
    }
    HasPtr(const HasPtr& ptr):
        ps(new std::string(*ptr.ps)), i(ptr.i), use(ptr.use) {
        ++* use;
        std::cout << "HasPtr(const HasPtr& ptr) called" << std::endl;
    }
    HasPtr& operator=(const HasPtr& rhs);
    HasPtr& operator=(const std::string& rhs);
    std::string& operator*();
    ~HasPtr();
private:
    std::string* ps;
    int i;
    std::size_t* use;
};

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    //  Step1
    ++* rhs.use;
    //  Step2
    if (-- * use == 0) {
        delete ps;
        delete use;
    }
    //  Step3
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;

    std::cout << "operator=(const HasPtr& rhs)" << std::endl;

    return *this;
}

#endif // !_HASPTR_H_