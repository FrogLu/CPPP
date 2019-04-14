#include "pch.h"
#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec& StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    
    return *this;
}

std::string& StrVec::operator[](std::size_t n)
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

const std::string& StrVec::operator[](std::size_t n) const
{
    const std::range_error arroob("StrVec out of bounds");
    try
    {
        if (n >= (first_free - elements)) {
            throw arroob;
        }
    }
    catch (const std::exception & arroob)
    {
        std::cout << arroob.what() << std::endl;
    }

    return elements[n];
}

void StrVec::push_back(const std::string& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, str);
}

void StrVec::push_back(std::string&& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, std::move(str));
}

void StrVec::reserve(std::size_t n)
{
    if (n > capacity()) {
        reallocate(n);
    }
}

void StrVec::resize(std::size_t n)
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

void StrVec::resize(std::size_t n, const std::string& str)
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

StrVec::~StrVec()
{
    free();
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* begin, const std::string* end)
{
    auto data = alloc.allocate(end - begin);

    return { data, uninitialized_copy(begin,end,data) };
}

void StrVec::free()
{
    if (elements) {
        //for (auto p = first_free; p != elements;/* void */) {
        //    alloc.destroy(--p);
        //}
        //auto p = first_free;
        std::for_each(elements, first_free, [](const std::string& str) {alloc.destroy(&str); });
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    reallocate(newcapacity);
}

void StrVec::reallocate(std::size_t newcapacity)
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

bool operator==(const StrVec& lhs, const StrVec& rhs)
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

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
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

bool operator<=(const StrVec& lhs, const StrVec& rhs)
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

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
    return rhs <= lhs;
}
