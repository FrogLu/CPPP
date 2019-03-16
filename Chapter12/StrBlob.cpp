#include "pch.h"
#include "StrBlob.h"

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>())
{
	// default is empty.
	
}

StrBlob::StrBlob(std::initializer_list<std::string> il)
	:data(std::make_shared<std::vector<std::string>>(il))
{
	// default is empty.
}

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
	return data->back();	// return type is std::string,data is not a const.
}

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> 
    StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock(); // "auto ret" is neccessary for return value
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    
    return ret;
}
