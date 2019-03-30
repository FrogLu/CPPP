#pragma once
#ifndef _HASPTR_H_
#define _HASPTR_H_

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) :
        ps(new std::string(s)), i(0) {
        std::cout << "HasPtr(const std::string& s = std::string()) called" << std::endl;
    }
    HasPtr(const HasPtr& ptr);
    HasPtr& operator=(const HasPtr& rhs);
    HasPtr& operator=(const std::string& rhs);
    std::string& operator*();
    ~HasPtr();
private:
    std::string* ps;
    //std::shared_ptr<std::string> ps;
    int i;
};

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

#endif // !_HASPTR_H_