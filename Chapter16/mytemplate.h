#pragma once
#ifndef _MYTEMPLATE_H_
#define _MYTEMPLATE_H_

#include <functional>
using std::less;

//  function template
template<typename T>
int compare(const T& v1, const T& v2) {
    if (std::less<T>()(v1, v2)) {
        return -1;
    }
    if (std::less<T>()(v1, v2)) {
        return 1;
    }
    return 0;
}


template<typename Titer,typename Tvalue>
Titer myfind(const Titer& begin, const Titer& end, const Tvalue& value) {
    while (begin != end && *begin != value) {
        ++begin;
    }
    return begin;
}


//  Just for arr
template<typename T,std::size_t N>
void print(const T (&arr)[N]) {
    for (auto iter = std::begin(arr); iter != std::end(arr); iter++) {
        std::cout << *iter << " ";
    }
}

template<typename Titer>
void print(const Titer& begin, const Titer& end) {
    for (auto iter = begin; iter != end; ++iter)
    {
        std::cout << *iter << " ";
    }
}

template<typename T, std::size_t N>
constexpr T* mybegin(T (&array)[N]) noexcept{
    return &array[0];   //  array is a left-reference to point to a T type array with N members.
}

template<typename T,std::size_t N>
constexpr T* myend(T (&array)[N]) noexcept{
    return &array[0] + N;
}


template <typename T, std::size_t N>
constexpr int arr_size(const T(&arr)[N]) {
    return N;
}


//  class template Blob
////    forward declarations begin
template <typename> class BlobPtr;
template <typename> class Blob; //  needed for parameters in operator==
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);
////    forward declarations end
template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::iterator iterator;

    Blob() :data(std::make_shared<std::vector<T>>()) {/*void*/};
    Blob(std::initializer_list<T> il)
        :data(std::make_shared<std::vector<T>>(il)) {/*void*/};

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty; }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();

    iterator begin() { return data->begin(); }
    iterator begin() const { return data->begin(); }
    iterator end() { return data->end(); }
    iterator end() const { return data->end(); }

    T& back();
    const T& back() const;
    T& front();
    const T& front() const;
    T& operator[](size_type i);
private:
    void do_back();
    void do_front();
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};

template <typename T>
const T& Blob<T>::front() const
{
    do_front();

    return data->front();
}

template <typename T>
T& Blob<T>::front()
{
    do_front();

    return data->front();
}

template <typename T>
void Blob<T>::do_front()
{
    check(0, "pop on empty Blob");
}

template <typename T>
const T& Blob<T>::back() const
{
    do_back();

    return data->back();
}


template<typename T>
inline void Blob<T>::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

template<typename T>
inline T& Blob<T>::back()
{
    do_back();
    return data->back();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");

    return (*data)[i];
}

template<typename T>
inline void Blob<T>::do_back()
{
    check(0, "back on empty Blob");
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string& msg) const
{
    if ((data->size()) <= i) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return (lhs.data) == (rhs.data);
}

//  class template Blob end


//  class template BlobPtr begin
////    forward declarations begin
template<typename T> class BlobPtr;
template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
////    forward declarations end
template <typename T> class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr():curr(0){/*void*/ }
    BlobPtr(Blob<T> &a,std::size_t sz=0):
        wptr(a.data),curr(sz){/*void*/ }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> 
    BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (ret->size() <= i) {
        throw std::out_of_range(msg);
    }

    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    BlobPtr ret = *this;
    --* this;
    
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    BlobPtr ret = *this;
    ++* this;
    
    return ret;
}
//  class template BlobPtr end


//  class template Screen begin
template<int H,int W>
class Screen {
public:
    Screen() :contents(H* W, ' ') {};
    Screen(const char c) :contents(H* W, c) {}
    friend class Window_mgr;
    char get() const { return contents[cursor]; }
    inline char get(int, int)const;
    Screen& clear(char = bkground);
private:
    static const char bkground = ' ';
public:
    Screen& move(int, int);
    Screen& set(char);
    Screen& set(int, int, char);
    Screen& display(std::ostream& os) {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const {
        do_display(os);
        return *this;
    }
private:
    void do_display(std::ostream& os)const { os << contents; }
    int cursor = 0;
    std::string contents;
};

template<int H, int W>
Screen<H, W>& Screen<H, W>::set(int r, int col, char ch)
{
    contents[r * W + col] = ch;

    return *this;
}

template<int H, int W>
Screen<H, W>& Screen<H, W>::set(char c) {
    contents[cursor] = c;

    return *this;
}

template<int H, int W>
inline  // not know why
Screen<H, W>& Screen<H, W>::move(int r, int c)
{
    int row = r * W;
    cursor = row + c;
    
    return *this;
}

template<int H, int W>
char Screen<H, W>::get(int r, int c) const
{
    int row = r * W;
    
    return contents[row + c];
}

template<int H,int W>
Screen<H, W>& Screen<H, W>::clear(char c) {
    contents = std::string(H * W, c);
    
    return *this;
}

template<typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.lock() == rhs.lock();
}

//  class template Screen end
#endif // _MYTEMPLATE_H_