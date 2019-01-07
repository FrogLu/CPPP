#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_
#include "Sales_data.h"

void elimDups(std::vector<std::string> &words);

bool isShorter(const std::string &s1, const std::string &s2);

bool compareIsbn(Sales_data & sd1, Sales_data & sd2);

void biggies(std::vector<std::string> &words,
	std::vector<std::string>::size_type sz);

bool stringgeq5(std::string & str);

const std::string make_plural(std::string::size_type count, const string &words,
	const string &suffix);

bool check_size(const std::string & s, std::string::size_type sz);

void printstr(const string & s);

#endif // _MYFUNCTION_H_


