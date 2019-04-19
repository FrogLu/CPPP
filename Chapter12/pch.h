#ifndef PCH_H
#define PCH_H

#include <iostream>
using std::cout; using std::ifstream; using std::ofstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <stdexcept>
using std::out_of_range;

#include <memory>
using std::shared_ptr; using std::unique_ptr; using std::weak_ptr;
using std::allocator; using std::uninitialized_copy; using std::uninitialized_copy_n;
using std::make_shared;

#include <fstream>

#include <cassert>

#include <new>
using std::nothrow;

#include <map>
using std::map;

#include <set>
using std::set;

#include <sstream>
using std::istringstream;
 
#endif // !PCH_H
