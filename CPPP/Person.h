#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

struct Person {
    friend std::istream &read(std::istream &is, Person &pre);
    friend std::ostream &print(std::ostream &os, Person &pre);
private:
    // ���ݳ�Ա
    std::string name;
    std::string address;
public:
    // ��Ա����
    std::string getName() {
        return this->name;
    }
    std::string getAdress() {
        return this->address;
    }
    // ���캯��
    Person() = default;
    Person(const string &name, const string &address) :name(name), address(address) {}
    Person(std::istream &is) {
        read(is, *this);
    }
};
std::istream &read(std::istream &is, Person &pre);
std::ostream &print(std::ostream &os, Person &pre);
#endif // !_PERSON_H_
