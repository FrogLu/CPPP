#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

struct Person {
//private:
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
std::istream &read(std::istream &is, Person &item);
std::ostream &print(std::ostream &os, Person &item);
#endif // !_PERSON_H_
