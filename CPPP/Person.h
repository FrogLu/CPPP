#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

struct Person {
private:
    //���ݳ�Ա
    std::string name;
    std::string address;
public:
    //��Ա����
    std::string getName() {
        return this->name;
    }
    std::string getAdress() {
        return this->address;
    }
};
#endif // !_PERSON_H_
