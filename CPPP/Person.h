#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

struct Person {
    //���ݳ�Ա
    std::string name;
    std::string address;
    //��Ա����
    std::string findName() {
        return this->name;
    }
    std::string findAdress() {
        return this->address;
    }
};
#endif // !_PERSON_H_
