#pragma once
#ifndef _STRVEC_H_
#define _STRVEC_H_

class StrVec
{
    friend bool operator==(const StrVec& lhs, const StrVec& rhs);
    friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
    friend bool operator<(const StrVec& lhs, const StrVec& rhs);
    friend bool operator<=(const StrVec& lhs, const StrVec& rhs);
    friend bool operator>(const StrVec& lhs, const StrVec& rhs);
    friend bool operator>=(const StrVec& lhs, const StrVec& rhs);
public:
    typedef std::vector<std::string>::size_type size_type;
    //  constructor
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(std::initializer_list<std::string> ilistr);
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;  //  paramenter1 can't be const, 
                                //  because we may change its value members in function body.
    StrVec& operator=(const StrVec&) &;
    StrVec& operator=(StrVec&&) noexcept ;
    //  user funciton
    StrVec& operator=(std::initializer_list<std::string> il);
    std::string& operator[](const std::size_t n);
    const std::string& operator[](const std::size_t n) const;
    void push_back(const std::string&);
    void push_back(std::string&&);
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
StrVec::StrVec(const StrVec& str) 
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline 
StrVec::StrVec(StrVec&& s) noexcept
    :elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

inline 
StrVec::StrVec(std::initializer_list<std::string> ilistr)
{
    auto newdata = alloc_n_copy(ilistr.begin(), ilistr.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline 
StrVec& StrVec::operator=(const StrVec& rhs) &
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline 
StrVec& StrVec::operator=(StrVec&& rhs) noexcept
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

inline
void StrVec::chk_n_alloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}

#endif // !_STRVEC_H_

