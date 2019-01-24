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
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::front()const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back() const 
{
	check(0, "back on empty StrBlob");
	return data->back();	// return type is std::string,data is not a const.
}