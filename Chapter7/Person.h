#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_
using std::string;

struct Person {
    friend std::istream &read(std::istream &is, Person &pre);
    friend std::ostream &print(std::ostream &os, Person &pre);
private:
    // 数据成员
    std::string name;
    std::string address;
public:
    // 成员函数
    std::string getName() {
        return this->name;
    }
    std::string getAdress() {
        return this->address;
    }
    // 构造函数
    Person() = default;
    Person(const std::string &name, const std::string &address) :
		name(name), address(address) {}
    explicit Person(std::istream &is) {
        read(is, *this);
    }
};
std::istream &read(std::istream &is, Person &pre);
std::ostream &print(std::ostream &os, Person &pre);
#endif // !_PERSON_H_
