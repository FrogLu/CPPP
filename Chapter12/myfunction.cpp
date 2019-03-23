#include "pch.h"
#include "myfunction.h"
#include "TextQuery.h"

connection connect(destination*) { connection c; return c; };
void disconnect(connection) {};
void end_connection(connection* p) {
    disconnect(*p);
}

void f(destination& d) {
    connection c = connect(&d);
    std::unique_ptr<connection, decltype(end_connection)*>
        p(&c, end_connection);
}

void myrunQueries(std::ifstream& infile) {
    std::vector<std::string> line;
    std::map<std::string, std::set<size_t>> rowMap;
    InitText(infile, line, rowMap);
    while (true) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string str;
        if (!(std::cin >> str) || str == "q") {
            break;
        }
        bool flag = true;
        auto iter=query(rowMap, str, flag);
        print(std::cout, iter, line, flag);
    }
}
void InitText(
    std::ifstream& infile,
    std::vector<std::string>& line,
    std::map<std::string, std::set<size_t>>& rowMap) {
    std::string linestr;
    size_t count = 0;
    while (std::getline(infile, linestr)) {
        ++count;
        line.push_back(linestr);
        std::istringstream inss(linestr);
        std::string word;
        while (inss >> word) {
            rowMap[word].insert(count);
        }
    }
}

std::map<std::string, std::set<size_t>>::iterator 
query(
    std::map<std::string, std::set<size_t>>& rowMap,
    const std::string& str,
    bool& flag) {
    auto ret = rowMap.find(str);    //  find() return a iterator
    if (ret == rowMap.cend()) {
        flag = false;
    }
    return ret;
}

void print(
    std::ostream& out, 
    const std::map<std::string, std::set<size_t>>::iterator& iter,
    const std::vector<std::string>& line,
    bool& flag) {
    if (flag == true) {
        for (auto& c : iter->second) {
            std::cout << c << " " << line[c - 1] << std::endl;
        }
    }
    else {
        std::cout << "Sorry,Can't find the word in paper." << std::endl;
    }
}