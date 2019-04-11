#pragma once
#ifndef _STRING_H_
#define _STRING_H_

//std::ostream& operator<<(std::ostream& out, const String& s);
class String
{
    friend std::ostream& operator<<(std::ostream& out,const String& s);
public:
    //  constructor
    String() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {};
    String(const char* cp);
    String(const String& str);
    String& operator=(const String& rhs);
    //  user function
    
    void push_back(const char& c);
    std::size_t size() { return first_free-elements; };
    std::size_t capacity() { return cap-elements; };
    void resize(std::size_t count, const char c = 'a');
    void reserve(std::size_t newcapacity);
    char* begin() const { return elements; };
    char* end() const { return first_free; };
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
    char* elements; //  cptr must behind sz and cap.
    char* first_free;
    char* cap;
};

inline 
String::String(const char* cp):
     elements(alloc.allocate(strlen(cp))),first_free(elements+std::strlen(cp)), cap(elements + std::strlen(cp))
{
    std::uninitialized_copy(cp, cp+strlen(cp), elements);
}

inline
String::String(const String& str) {
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = cap = newdata.second;

    std::cout << "String::String(const String& str) called" << std::endl;
}
inline String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    std::cout << "String::operator=(const String& rhs) called" << std::endl;

    return *this;
}

inline
std::ostream& operator<<(std::ostream& out,const String& s) {
    for (auto p = s.elements; p != s.first_free; ++p) {
        out << *p;
    }
    return out;
}

inline 
void String::free()
{
    if (elements) {
        alloc.deallocate(elements, cap-elements);
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

