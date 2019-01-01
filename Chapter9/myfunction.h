#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_
using std::vector; using std::string;
std::vector<int> get_next(const std::string& P);
int replace_string_KMP(std::string &s, const std::string &p1,
						const std::string p2);
std::string& fullname(std::string& name, const std::string& prefix,
						const std::string& suffix);
std::vector<std::string::size_type> findnum(std::string &str);
std::vector<std::string::size_type>  findletter(std::string &str);
bool findword(std::string& word);
void elimDups(std::vector<std::string>& words);
bool isShorter(const std::string & s1, const std::string & s2);
#endif // !_MYFUNCTION_H_
