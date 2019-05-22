#pragma once
#ifndef _tVec_H_
#define _tVec_H_

#include "pch.h"
//  class template tVec begin
template<typename T>
class tVec
{
    friend bool operator==(const tVec& lhs, const tVec& rhs);
    friend bool operator!=(const tVec& lhs, const tVec& rhs);
    friend bool operator<(const tVec& lhs, const tVec& rhs);
    friend bool operator<=(const tVec& lhs, const tVec& rhs);
    friend bool operator>(const tVec& lhs, const tVec& rhs);
    friend bool operator>=(const tVec& lhs, const tVec& rhs);
public:
    typedef typename std::vector<T>::size_type size_type;
    //  constructor
    tVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {};
    tVec(std::initializer_list<T> ilistr);
    tVec(const tVec&);
    tVec(tVec&&) noexcept;  //  paramenter1 can't be const, 
                                //  because we may change its value members in function body.
    tVec& operator=(const tVec&) &;
    tVec& operator=(tVec&&) noexcept;
    //  user function
    tVec& operator=(std::initializer_list<T> il);
    T& operator[](const std::size_t n);
    const T& operator[](const std::size_t n) const;
    void push_back(const T&);
    void push_back(T&&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    void reserve(std::size_t n);
    void resize(std::size_t n);
    void resize(std::size_t n, const T& str);
    T* begin() const { return elements; }
    T* end() const { return first_free; }
    //  destructor
    ~tVec();
private:
    static std::allocator<T> alloc;
    void chk_n_alloc();
    std::pair<T*, T*>
        alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    void reallocate(std::size_t newcapacity);
    T* elements;
    T* first_free;
    T* cap;
};

template<typename T>
inline
tVec<T>::tVec(const tVec& str)
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
inline
tVec<T>::tVec(tVec&& s) noexcept
    :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
inline
tVec<T>::tVec(std::initializer_list<T> ilistr)
{
    auto newdata = alloc_n_copy(ilistr.begin(), ilistr.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
inline
tVec<T>& tVec<T>::operator=(const tVec& rhs) &
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
inline
tVec<T>& tVec<T>::operator=(tVec&& rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

template<typename T>
inline
void tVec<T>::chk_n_alloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

template<typename T>
std::allocator<T> tVec<T>::alloc;

template<typename T>
tVec<T>& tVec<T>::operator=(std::initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

template<typename T>
T& tVec<T>::operator[](const std::size_t n)
{
    const std::range_error arroob("StrVec out of bounds");
    try
    {
        if (n >= (first_free - elements)) {
            throw arroob;
        }
    }
    catch (const std::exception& arroob)
    {
        std::cout << arroob.what() << std::endl;
    }

    return elements[n];
}

template<typename T>
const T& tVec<T>::operator[](const std::size_t n) const
{
    const std::range_error arroob("StrVec out of bounds");
    try
    {
        if (n >= (first_free - elements)) {
            throw arroob;
        }
    }
    catch (const std::exception& arroob)
    {
        std::cout << arroob.what() << std::endl;
    }

    return elements[n];
}

template<typename T>
void tVec<T>::push_back(const T& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, str);
}

template<typename T>
void tVec<T>::push_back(T&& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, std::move(str));
}

template<typename T>
void tVec<T>::reserve(std::size_t n)
{
    if (n > capacity()) {
        reallocate(n);
    }
}

template<typename T>
void tVec<T>::resize(std::size_t n)
{
    if (n > size()) {
        while (size() < n) {
            push_back("");
        }
    }
    else if (n < size()) {
        while (size() > n) {
            alloc.destroy(--first_free);
        }
    }
}

template<typename T>
void tVec<T>::resize(std::size_t n, const T& str)
{
    if (n > size()) {
        while (size() < n) {
            push_back(str);
        }
    }
    else if (n < size()) {
        std::cout << "Warning: first parameter less than the size." << std::endl;
        while (size() > n) {
            alloc.destroy(--first_free);
        }
    }
}

template<typename T>
tVec<T>::~tVec()
{
    free();
}

template<typename T>
std::pair<T*, T*>
tVec<T>::alloc_n_copy(const T* begin, const T* end)
{
    auto data = alloc.allocate(end - begin);

    return { data, std::uninitialized_copy(begin,end,data) };
}

template<typename T>
void tVec<T>::free()
{
    if (elements) {
        //for (auto p = first_free; p != elements;/* void */) {
        //    alloc.destroy(--p);
        //}
        //auto p = first_free;
        std::for_each(elements, first_free, [](const T& str) {alloc.destroy(&str); });
        alloc.deallocate(elements, cap - elements);
    }
}

template<typename T>
void tVec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    reallocate(newcapacity);
}

template<typename T>
void tVec<T>::reallocate(std::size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);

    auto dest = std::uninitialized_copy(std::make_move_iterator(begin()),
        std::make_move_iterator(end()),
        newdata);
    //auto elem = elements;
    //for (std::size_t i = 0; i != size(); ++i) {
    //    alloc.construct(dest++, std::move(*elem++));
    //}

    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template<typename T>
bool operator==(const tVec<T>& lhs, const tVec<T>& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }

    for (auto iter1 = lhs.begin(), iter2 = rhs.begin();
        iter1 != lhs.end() && iter2 != rhs.end();
        ++iter1, ++iter2) {
        if (*iter1 != *iter2) {
            return false;
        }
    }

    return true;    // for both are null, then it won't enter for loop.
}

template<typename T>
bool operator!=(const tVec<T>& lhs, const tVec<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const tVec<T>& lhs, const tVec<T>& rhs)
{
    auto iter1 = lhs.begin(), iter2 = rhs.begin();
    for (/*void*/;
        iter1 != lhs.end() && iter2 != rhs.end();
        ++iter1, ++iter2) {
        if (*iter1 != *iter2) {
            return (*iter1) < (*iter2);
        }
    }
    if (iter1 == lhs.end() && iter2 != rhs.end()) {
        return true;
    }

    return false;    // for both are null, then it won't enter for loop.
}

template<typename T>
bool operator<=(const tVec<T>& lhs, const tVec<T>& rhs)
{
    auto iter1 = lhs.begin(), iter2 = rhs.begin();
    for (/*void*/;
        iter1 != lhs.end() && iter2 != rhs.end();
        ++iter1, ++iter2) {
        if (*iter1 != *iter2) {
            return (*iter1) < (*iter2);
        }
    }
    if (iter1 == lhs.end()) {
        return true;
    }

    return false;    // for both are null, then it won't enter for loop.
}

template<typename T>
bool operator>(const tVec<T>& lhs, const tVec<T>& rhs)
{
    return rhs < lhs;
}

template<typename T>
bool operator>=(const tVec<T>& lhs, const tVec<T>& rhs)
{
    return rhs <= lhs;
}
//  class template tVec end
#endif // _tVec_H_

