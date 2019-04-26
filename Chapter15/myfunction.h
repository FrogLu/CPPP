#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

struct destination {
    destination()=default;

};
struct connection {
    connection() = default;
};
connection connect(destination*);
void disconnect(connection);
void end_connection(connection* p);
void f(destination& d);

void myrunQueries(std::ifstream& infile);
void InitText(std::ifstream& infile, std::vector<std::string>& line, std::map<std::string, std::set<std::size_t>>& rowMap);
std::map<std::string, std::set<std::size_t>>::iterator query(std::map<std::string, std::set<std::size_t>>& rowMap, const std::string& str, bool& flag);
void print(std::ostream& out, const std::map<std::string, std::set<std::size_t>>::iterator& iter, const std::vector<std::string>& line, bool& flag);
const std::string make_plural(std::string::size_type count, const std::string& words,const std::string& suffix);
#endif // !_MYFUNCTION_H_