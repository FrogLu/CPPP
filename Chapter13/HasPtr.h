#pragma once
#ifndef _HASPTR_H_
#define _HASPTR_H_

// swap is non-member function, so don't need forward declaration.
//void swap(HasPtr& lhs, HasPtr& rhs);
class HasPtr {
    friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
    HasPtr(const std::string& s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {
        std::cout << "HasPtr(const std::string& s = std::string()) called" << std::endl;
    };
    HasPtr(const HasPtr& ptr) :
        ps(new std::string(*ptr.ps)), i(ptr.i), use(ptr.use) {
        ++* use;
        std::cout << "HasPtr(const HasPtr& ptr) called" << std::endl;
    };
    HasPtr(HasPtr&& ptr) noexcept :
        ps(ptr.ps), i(ptr.i),use(ptr.use) {
        ptr.ps = 0;
    };
    HasPtr& operator=(const HasPtr& rhs);
    HasPtr& operator=(HasPtr&& rhs) noexcept;   
    HasPtr& operator=(const std::string& rhs);
    bool operator<(const HasPtr& rhs);
    std::string& operator*();
    std::string get();
    ~HasPtr();
private:
    std::string* ps;
    int i;
    std::size_t* use;
};

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newptr = new std::string(*rhs.ps);
    delete ps;  //  destory origin string
    ps = newptr;    // point to a new string
    i = rhs.i;
    return *this;

}

inline 
HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept
{
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        rhs.ps = nullptr;
        rhs.i = 0;
    }

    std::cout << "HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept called" << std::endl;

    return *this;
}

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::cout << "swap() is called" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#endif // !_HASPTR_H_