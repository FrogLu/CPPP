#pragma once
#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyIfElse {
public:
    MyIfElse() = default;
    MyIfElse(const std::size_t i1, const std::size_t i2, const std::size_t i3) :iVal1(i1),iVal2(i2), iVal3(i3) {}
    std::size_t operator()(const std::size_t, const std::size_t& first, const std::size_t& last);
private:
    const std::size_t iVal1, iVal2, iVal3;
};

inline
std::size_t MyIfElse::operator()(const std::size_t condition, const std::size_t& first, const std::size_t& last) {
    return condition ? first : last;
}

#endif // !_MYCLASS_H_
