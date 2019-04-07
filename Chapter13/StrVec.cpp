#include "pch.h"
#include "StrVec.h"



StrVec::StrVec()
{
}

void StrVec::push_back(const std::string& str) {
    chk_n_alloc();

    alloc.construct(first_free++, str);
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
