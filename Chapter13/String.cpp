#include "pch.h"
#include "String.h"

std::allocator<char> String::alloc;

std::pair<char*, char*>
String::alloc_n_copy(const char* begin, const char* end) {
    auto data = alloc.allocate(end - begin);

    return { data,std::uninitialized_copy(begin,end,data) };
}

void String::reallocate()
{
    auto newcapacity = capacity() ? 2 * size() : 1;
    reallocate(newcapacity);
}

void String::reallocate(std::size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto cp = cptr;
    for (std::size_t count = 0; count != sz; ++count) {
        alloc.construct(dest++, std::move(*cp++));
    }
    free();
    cptr = newdata;
    sz = dest - newdata;
    cap = newcapacity;
}

void String::push_back(const char& c) {
    chk_n_alloc();
    alloc.construct(cptr+sz++, c);
}

void String::resize(std::size_t count, const char c)
{
    if (count > sz) {
        while (sz < count) {
            push_back(c);
        }
    }
    else if (count < sz) {
        while (sz > count) {
            alloc.destroy(--sz+cptr);
        }
    }
}


void String::reserve(std::size_t newcapacity)
{
    if (newcapacity > capacity()) {
        reallocate(newcapacity);
    }
    
}

String::~String()
{
    free();
}
