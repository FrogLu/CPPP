#pragma once
#ifndef _STRBLOB_H_
#define _STRBLOB_H_

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;    // friend is necessary for StrBlobPtr's constructor to access a.data
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(std::vector<std::string>* p);
    StrBlob(const StrBlob& sb);
    StrBlob& operator=(const StrBlob& rhs);
    size_type size()const { return data->size(); }
    bool empty()const { return data->empty(); }
    void push_back(const std::string& t) { data->push_back(t); }
    void pop_back();
    std::string& front();
    const std::string& front()const;
    std::string& back();
    const std::string& back() const;

    // StrBlobPtr function
    StrBlobPtr begin(); // can't be defined until StrBlobPtr is!!!!!!!!!!!!!
    StrBlobPtr end();
    StrBlobPtr begin()const; // can't be defined until StrBlobPtr is!!!!!!!!!!!!!
    StrBlobPtr end()const;
private:
    void do_front() const;
    void do_back()  const;
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

inline
StrBlob::StrBlob() 
    :data(std::make_shared<std::vector<std::string>>())
{
    // default is empty.

}

inline
StrBlob::StrBlob(std::initializer_list<std::string> il)
    :data(std::make_shared<std::vector<std::string>>(il))
{
    // default is empty.
}

inline StrBlob::StrBlob(std::vector<std::string>* p)
    : data(p)
{

}

inline StrBlob::StrBlob(const StrBlob& sb) :
    data(std::make_shared<std::vector<std::string>>(*sb.data))
{
    return;
}

inline StrBlob& StrBlob::operator=(const StrBlob& rhs)
{
    data = make_shared<std::vector<std::string>>(*rhs.data);
    
    return *this;
}

inline 
void StrBlob::do_front() const {
    check(0, "front on empty StrBlob");
}

inline 
void StrBlob::do_back()  const {
    check(0, "back on empty StrBlob");
}

//  class StrBlobPtr part
bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs);    //  forward declaration

class StrBlobPtr {
    friend bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
public:
    StrBlobPtr() :curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
    StrBlobPtr(const StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
    std::string& deref() const;
    std::string& deref(size_t off) const;
    StrBlobPtr& incr();
    StrBlobPtr& add(size_t num);
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t i , const std::string& msg)   const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

inline
StrBlobPtr StrBlob::begin() {   // begin() & end() will be used frequently so inline is needed.
    return StrBlobPtr(*this);
}

inline
StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this);
}

inline
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

inline
StrBlobPtr StrBlob::end() const{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// operator for StrBlobPtr
inline
bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {   // inline is needed if defined in .h, not needed in .cpp
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r) {
        return (!r || lhs.curr == rhs.curr);    // there are two situations. both null or just same,
                                                //  but return value is different.
    }
    else {
        return false;
    }
}


#endif // !_STRBLOB_H_
