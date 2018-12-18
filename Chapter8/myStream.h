#pragma once
#ifndef _MYSTREAM_H_
#define _MYSTREAM_H_
#include <iostream>
std::istream& myprint(std::istream& is);
bool process(std::ifstream& ifs, std::vector<string>& vstr);
bool process(std::ofstream& ofs, std::vector<string>& vstr);

struct PersonInfo {
	string name;
	vector<string> phones;
};
#endif // !_MYSTREAM_H_