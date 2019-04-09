#pragma once
#ifndef _STRING_H_
#define _STRING_H_

class String
{
public:
    //  constructor
    String() :
        sz(0),cap(0),cptr(nullptr) {};
    String(char* cp);
    String(const String& str);
    String& operator=(const String& rhs);
    //  user function
    void push_back(const char& c);
    std::size_t size() { return sz; };
    std::size_t capacity() { return cap; };
    void resize(std::size_t count, const char c = 'a');
    void reserve(std::size_t newcapacity);
    char* begin() const { return cptr; };
    char* end() const { return cptr + sz; };
    //  destructor
    ~String();
private:
    //  function
    void free();
    void chk_n_alloc();
    std::pair<char*, char*> 
        alloc_n_copy(const char*, const char*);
    void reallocate();
    void reallocate(std::size_t newcapacity);
    //  data
    static std::allocator<char> alloc;
    std::size_t sz = 0;
    std::size_t cap = 0;
    char* cptr; //  cptr must behind sz and cap.
    
};

inline String::String(char* cp):
     sz(std::strlen(cp)), cap(std::strlen(cp)),cptr(alloc.allocate(cap))
{
    std::uninitialized_copy(cp, cp + sz, cptr);
}

inline
String::String(const String& str) {
    auto newdata = alloc_n_copy(str.begin(), str.end());
    cptr = newdata.first;
    sz = cap = newdata.second-newdata.first;

    
}
inline String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    cptr = data.first;
    sz = cap = data.second-data.first;
    return *this;
}

inline 
void String::free()
{
    if (cptr) {
        alloc.deallocate(cptr, sz);
    }
}

inline
void String::chk_n_alloc()
{
    if (size() == capacity()) {
        reallocate();
    }
}
#endif // !_STRING_H_

