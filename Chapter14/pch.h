#pragma once
#ifndef _PCH_H_
#define _PCH_H_


#include <iostream>
using std::istream; using std::ostream;
using std::cout; using std::endl;

#include <string>
using std::string; using std::getline;

#include <vector>
using std::vector;

#include <stdexcept>
using std::range_error;

#include <algorithm>
using std::for_each; using std::replace_if; using std::transform;

#include <memory>
using std::make_shared;

#include <initializer_list>
using std::initializer_list;

#include <fstream>
using std::ifstream;

#include <cassert>

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <functional>
using std::bind; using std::placeholders::_1; using std::not_equal_to; using std::function;
using std::plus; using std::minus; using std::multiplies; using std::divides; using std::modulus;

#include <map>
using std::map;

#endif // !_PCH_H_
