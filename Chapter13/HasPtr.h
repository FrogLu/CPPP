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
    HasPtr& operator=(const HasPtr& ptr);
    ~HasPtr();
private:
    std::string* ps;
    //std::shared_ptr<std::string> ps;
    int i;
};

#endif // !_HASPTR_H_