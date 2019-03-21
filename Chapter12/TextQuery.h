#pragma once
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
void runQueries(std::ifstream& infile);
class TextQuery {

public:
    typedef std::vector<std::string> VSTR;
    typedef std::map<std::string, std::set<int>> MAP;   //code in here 3/21
    TextQuery() = default;
    TextQuery(const VSTR& svec, const MAP& rowcount) :text(svec), rowMap(rowcount) {};
    TextQuery(std::ifstream& infile);
    MAP::iterator query(std::string& str);
private:
    VSTR text;
    MAP rowMap;
};
inline
TextQuery::TextQuery(std::ifstream& infile) {
    std::string linestr;
    int count = 0;
    while (getline(infile, linestr)) {
        ++count;
        text.push_back(linestr);
        std::istringstream line(linestr);
        std::string word;
        while (line >> word) {
            rowMap[word].insert(count);
        }
    }
}

inline 
TextQuery::MAP::iterator TextQuery::query(std::string& str)
{
    auto ret = rowMap.find(str);
    return ret;
}

class QueryResult {

    friend std::ostream& print(std::ostream& out, const TextQuery::MAP::iterator& iter);
public:
    QueryResult() = default;
private:
    std::shared_ptr<TextQuery::MAP::iterator> sptr;
};

#endif // !_TEXTQUERY_H_