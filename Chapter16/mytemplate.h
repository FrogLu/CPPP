#pragma once
#ifndef _MYTEMPLATE_H_
#define _MYTEMPLATE_H_

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


template<typename Titer,typename Tvalue>
Titer myfind(const Titer& begin, const Titer& end, const Tvalue& value) {
    while (begin != end && *begin != value) {
        ++begin;
    }
    return begin;
}


//  Just for arr
template<typename T,size_t N>
void print(const T (&arr)[N]) {
    for (auto iter = std::begin(arr); iter != std::end(arr); iter++) {
        std::cout << *iter << " ";
    }
}


template<typename T, std::size_t N>
constexpr T* mybegin(T (&array)[N]) noexcept{
    return &array[0];   //  array is a left-reference to point to a T type array with N members.
}

template<typename T,std::size_t N>
constexpr T* myend(T (&array)[N]) noexcept{
    return &array[0] + N;
}
#endif // _MYTEMPLATE_H_