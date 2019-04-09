#pragma once
#ifndef _STRVEC_H_
#define _STRVEC_H_

class StrVec
{

public:
    typedef std::vector<std::string>::size_type size_type;
    //  constructor
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string> ilistr);
    StrVec& operator=(const StrVec&);
    //  user funciton
    void push_back(const std::string&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    void reserve(std::size_t n);
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string& str);
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    //  destructor
    ~StrVec();
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*>
        alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    void reallocate(std::size_t newcapacity);
    std::string* elements;
    std::string* first_free;
    std::string* cap;
};

inline 
StrVec::StrVec(const StrVec& str) {
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline 
StrVec::StrVec(std::initializer_list<std::string> ilistr)
{
    auto newdata = alloc_n_copy(ilistr.begin(), ilistr.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline 
StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline
void StrVec::chk_n_alloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

#endif // !_STRVEC_H_
