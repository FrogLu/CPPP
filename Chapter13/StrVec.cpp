#include "pch.h"
#include "StrVec.h"



StrVec::StrVec()
{
}

void StrVec::push_back(const std::string& str) {
    chk_n_alloc();

    alloc.construct(first_free++, str);
}

void StrVec::reserve(std::size_t n)
{
    if (n > size()) {
        auto newdata = alloc.allocate(n);

        auto dest = newdata;
        auto elem = elements;
        for (std::size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + n;
    }
}

void StrVec::resize(std::size_t n)
{
    chk_n_alloc();
    if (n > size()) {
        auto temp_first_free = first_free;
        while (n > capacity()) {
            reallocate();
        }
        for (std::size_t i = 0; i != (n-size()); ++i) {
            alloc.construct(first_free++, std::string());
        }
    }
    else if (n < size()) {
        auto p = first_free;
        for (std::size_t i=0; i != (size()-n);++i) {
            alloc.destroy(--p);
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
        for (auto p = first_free; p != elements;/* void */) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
