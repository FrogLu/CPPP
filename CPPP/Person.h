#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

struct Person {
    //数据成员
    std::string name;
    std::string address;
    //成员函数
    std::string findName() {
        return this->name;
    }
    std::string findAdress() {
        return this->address;
    }
};
#endif // !_PERSON_H_
