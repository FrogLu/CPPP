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
    auto cp = elements;
    for (auto p=elements; p != first_free; ++p) {
        alloc.construct(dest++, std::move(*cp++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

char& String::operator[](const std::size_t n)
{
    const std::range_error arroob("String out of bounds");
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

const char& String::operator[](const std::size_t n) const
{
    const std::range_error arroob("String out of bounds");
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

void String::push_back(const char& c) {
    chk_n_alloc();
    alloc.construct(first_free++, c);
}

void String::resize(std::size_t count, const char c)
{
    if (count > size()) {
        while (size() < count) {
            push_back(c);
        }
    }
    else if (count < size()) {
        while (size() > count) {
            alloc.destroy(--first_free);
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
