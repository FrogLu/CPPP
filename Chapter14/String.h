#pragma once
#ifndef _STRING_H_
#define _STRING_H_

//std::ostream& operator<<(std::ostream& out, const String& s);
class String
{
    friend std::ostream& operator<<(std::ostream& out,const String& s);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    friend bool operator<(const String& lhs, const String& rhs);
    friend bool operator<=(const String& lhs, const String& rhs);
    friend bool operator>(const String& lhs, const String& rhs);
    friend bool operator>=(const String& lhs, const String& rhs);
public:
    //  constructor
    String() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {};
    String(const char* cp);
    String(const String& str);
    String(String&& str) noexcept;
    String& operator=(const String& rhs);
    String& operator=(String&& rhs) noexcept;
    //  user function
    char& operator[](const std::size_t n);
    const char& operator[](const std::size_t n)const;
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
inline 
String::String(String&& str) noexcept
    :elements(str.elements),first_free(str.first_free),cap(str.cap)
{
    str.elements = str.first_free = str.cap = nullptr;

    std::cout << "String::String(String&& str) noexcept called" << std::endl;
}

inline 
String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    std::cout << "String::operator=(const String& rhs) called" << std::endl;

    return *this;
}

inline 
String& String::operator=(String&& rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    std::cout << "String& String::operator=(String&& rhs) noexcept called" << std::endl;

    return *this;
}

inline
std::ostream& operator<<(std::ostream& out,const String& s) {
    for (auto p = s.elements; p != s.first_free; ++p) {
        out << *p;
    }

    return out;
}

inline bool operator==(const String& lhs, const String& rhs)
{
    return strcmp(lhs.elements, rhs.elements);
}

inline bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

inline bool operator<(const String& lhs, const String& rhs)
{
    return strcmp(lhs.elements, rhs.elements) < 0;
}

inline bool operator<=(const String& lhs, const String& rhs)
{
    return !(rhs < lhs);
}

inline bool operator>(const String& lhs, const String& rhs)
{
    return rhs < lhs;
}

inline bool operator>=(const String& lhs, const String& rhs)
{
    return !(lhs < rhs);
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

