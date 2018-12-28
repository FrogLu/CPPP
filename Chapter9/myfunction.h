#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

std::vector<int> get_next(const string& P);
int replace_string_KMP(string &s, const string &p1, const string p2);
string& fullname(string& name, const string& prefix, const string& suffix);
std::vector<std::string::size_type> findnum(std::string &str);
std::vector<std::string::size_type>  findletter(std::string &str);
#endif // !_MYFUNCTION_H_
