#include "stdafx.h"
#include "Person.h"

std::istream &read(std::istream &is, Person &pre) {
    is >> pre.name >> pre.address;

    return is;
}
std::ostream &print(std::ostream &os, Person &pre) {
    os << pre.name << " " << pre.address;

    return os;
}