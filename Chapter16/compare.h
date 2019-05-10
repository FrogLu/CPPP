#pragma once
#ifndef _COMPARE_H_
#define _COMPARE_H_
#include <functional>
using std::less;

template<typename T>
int compare(const T& v1, const T& v2) {
    if (std::less<T>()(v1, v2)) {
        return -1;
    }
    if (std::less<T>()(v1, v2)) {
        return 1;
    }
    return 0;
}

#endif // _COMPARE_H_