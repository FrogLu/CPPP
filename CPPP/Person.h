#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

struct Person {
//private:
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
std::istream &read(std::istream &is, Person &item);
std::ostream &print(std::ostream &os, Person &item);
#endif // !_PERSON_H_
