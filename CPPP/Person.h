#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

struct Person {
private:
    //数据成员
    std::string name;
    std::string address;
public:
    //成员函数
    std::string getName() {
        return this->name;
    }
    std::string getAdress() {
        return this->address;
    }
};
#endif // !_PERSON_H_
