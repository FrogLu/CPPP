#include "pch.h"
#include "StrBlob.h"

void StrBlob::check(size_type i, const std::string& msg) const
{
	if ((data->size()) <= i) {
		throw std::out_of_range(msg);
	}
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front()
{
    do_front();
	return data->front();
}

const std::string& StrBlob::front()const
{
    do_front();
	return data->front();
}

std::string& StrBlob::back()
{
    do_back();
	return data->back();
}

const std::string& StrBlob::back() const 
{
    do_back();
	return data->back();	// return type is std::string, data is not a const.
}


std::string& StrBlobPtr::operator[](const std::size_t n)
{
    const std::range_error arroob("StrVec out of bounds");
    try
    {
        if (n >= curr) {
            throw arroob;
        }
    }
    catch (const std::exception & arroob)
    {
        std::cout << arroob.what() << std::endl;
    }

    return (*wptr.lock())[n];
}

const std::string& StrBlobPtr::operator[](const std::size_t n) const
{
    const std::range_error arroob("StrVec out of bounds");
    try
    {
        if (n >= curr) {
            throw arroob;
        }
    }
    catch (const std::exception & arroob)
    {
        std::cout << arroob.what() << std::endl;
    }

    return (*wptr.lock())[n];
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;

    return *this;
}

StrBlobPtr& StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++* this;

    return ret;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");

    return *this;
}

StrBlobPtr& StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --* this;
    
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(const std::size_t num)
{
    auto ret = *this;
    ret.curr += num;
    //  can't return *this, the return value wouldn't impact *this(object).
    //  so ret.curr doesn't need check(), and can't call ret.check() in this function.
    return ret;     
}

StrBlobPtr StrBlobPtr::operator-(const std::size_t num)
{
    auto ret = *this;
    ret.curr += num;

    return ret;
}

std::string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");

    return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const
{
    return &(this->operator*());
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string& StrBlobPtr::deref(size_t off) const
{
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::add(size_t num)
{
    check(curr + num, "add past end of StrBlobPtr");
    curr += num;
    return *this;
}

std::shared_ptr<std::vector<std::string>> 
    StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock(); // "auto ret" is necessary for return value
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    
    return ret;
}
