#pragma once
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

void runQueries(std::ifstream& infile);
class QueryResult;
class TextQuery {
    friend class QueryResult;
public:
    typedef std::vector<std::string> VSTR;
    typedef std::map<std::string, std::set<int>> MAP;   //code in here 3/21
    TextQuery() = default;
    TextQuery(const VSTR& svec, const MAP& rowcount) :text(svec), rowMap(rowcount) {};
    TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& str);
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

class QueryResult {
    
    friend std::ostream& print(std::ostream& out, const QueryResult result);
public:
    typedef std::shared_ptr<TextQuery::MAP::iterator> SP;
    typedef std::shared_ptr<std::vector<std::string>> SVS;
    QueryResult() = default;
    QueryResult(SP sp, SVS curr,bool bf) :sptr(sp), spline(curr),flag(bf) {};
private:
    std::shared_ptr<TextQuery::MAP::iterator> sptr;
    std::shared_ptr<std::vector<std::string>> spline;
    bool flag=true;
};

// without inline, it will pop LNK2005 and LNK1169, multi define symbol, don't know why
inline
void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string str;
        if (!(std::cin >> str) || str == "q") {
            break;
        }
        print(std::cout, tq.query(str)) << std::endl;
    }
}

inline
std::ostream& print(std::ostream& out, const QueryResult result)
{
    if (result.flag == true) {
        for (auto c : (*result.sptr)->second) {
            out << c << " " << (*result.spline)[c-1] << std::endl;
        }
    }
    else {
        out << "Sorry,Can't find the word in paper." << std::endl;
    }
    return out;
}

inline
QueryResult TextQuery::query(const std::string& str)
{
    bool flag = true;
    auto iter = rowMap.find(str);
    if (iter == rowMap.cend()) {
        flag = false;
    }
    // if not use make_shared it will trigge exception in proxy and delete, but don't know why!!!
    //std::shared_ptr<MAP::iterator> spiter(&iter);
    std::shared_ptr<MAP::iterator> spiter = make_shared<MAP::iterator>(iter);   
    //std::shared_ptr<VSTR> spline(&text);                                      
    std::shared_ptr<VSTR> spline = make_shared<VSTR>(text);
    QueryResult ret(spiter, spline,flag);
    return ret;
}

#endif // !_TEXTQUERY_H_