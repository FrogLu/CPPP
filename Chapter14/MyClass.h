#pragma once
#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyIfElse {
public:
    std::size_t operator()(const bool condition, const std::size_t& first, const std::size_t& last);
};

inline
std::size_t MyIfElse::operator()(const bool condition, const std::size_t& first, const std::size_t& last) {
    if (condition) {
        return first;
    }
    else {
        return last;
    }
}

#endif // !_MYCLASS_H_
