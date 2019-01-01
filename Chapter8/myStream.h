#pragma once
#ifndef _MYSTREAM_H_
#define _MYSTREAM_H_
using std::ifstream; using  std::ofstream;
using std::vector; using std::string;

std::istream& myprint(std::istream& is);
bool process(std::ifstream& ifs, std::vector<string>& vstr);
bool process(std::ofstream& ofs, std::vector<string>& vstr);
std::vector<int>::iterator myfind(std::vector<int> vint, const int& val);
struct PersonInfo {
	std::string name;
	std::vector<string> phones;
};
#endif // !_MYSTREAM_H_