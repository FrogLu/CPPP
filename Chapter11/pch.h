// pch.h: This is a precompiled header file. 
// Files listed below are compiled only once, improving build performance for future builds. 
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds. 
// Do not add files that you will frequently be updating here (this negates the performance advantage).

#ifndef PCH_H
#define PCH_H

using std::size_t;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <map>
using std::map;

#include <set>
using std::set; using std::multiset;

#include <string>
using std::string;

#include <fstream>

#include <vector>

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <cassert>

#include <sstream>
using std::istringstream;

#include <algorithm>
using std::unique;

#include <list>
using std::list;

#include <unordered_map>
using std::unordered_map;

#include <utility>
using std::pair;

#include <stdexcept>
using std::runtime_error;

#endif //PCH_H
