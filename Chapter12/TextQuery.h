#pragma once
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "StrBlob.h"

void runQueries(std::ifstream& infile);
class QueryResult;
class TextQuery {
    friend class QueryResult;
public:
    using SVST=StrBlob::size_type;
    //typedef std::vector<std::string>::size_type SVST;
    typedef StrBlob  VSTR;
    typedef std::map<std::string, std::shared_ptr<std::set<SVST> > > MAP;
    TextQuery() = default;
    TextQuery(const VSTR& svec, const MAP& rowcount) :text(svec), rowMap(rowcount) {};
    TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& str);
private:
    VSTR text;
    MAP rowMap;
};
inline
TextQuery::TextQuery(std::ifstream& infile):text(new std::vector<std::string>) {
    std::string linestr;
    
    while (getline(infile, linestr)) {
        
        text.push_back(linestr);
        SVST count = text.size() - 1;
        std::istringstream line(linestr);
        std::string word;
        while (line >> word) {
            //rowMap[word].insert(count);
            auto& lines = rowMap[word];
            if (!lines) {
                lines.reset(new std::set<SVST>);
            }
            lines->insert(count);
        }
    }
}

class QueryResult {
    
    friend std::ostream& print(std::ostream& out, const QueryResult& result);
public:
    typedef std::shared_ptr<std::set<TextQuery::SVST> > SP;
    typedef StrBlobPtr SVS;
    QueryResult() = default;
    QueryResult(SP sp, SVS curr,const std::string sg) :sptr(sp), spline(curr),sought(sg) {};
    std::set<TextQuery::SVST>::iterator begin();
    const std::set<TextQuery::SVST>::iterator begin()const;
    std::set<TextQuery::SVST>::iterator end();
    const std::set<TextQuery::SVST>::iterator end()const;
    StrBlobPtr get_spline() { return spline; }
private:
    SP sptr;
    SVS spline;
    std::string sought;
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
std::ostream& print(std::ostream& out, const QueryResult& result)
{
    out << result.sought << " occurs " << result.sptr->size() << " "
        << make_plural(result.sptr->size(), "time", "s") << std::endl;
    for (auto num : *result.sptr) {
        out << "\t(line " << num + 1 << ") "
            << result.spline.deref(num) << std::endl;
    }
    return out;
}

inline
QueryResult TextQuery::query(const std::string& sought)
{
    static std::shared_ptr<std::set<SVST> > nodata;
    auto iter = rowMap.find(sought);
    if (iter == rowMap.cend()) {
        return QueryResult(nodata,text,sought);
    }
    else {
        return QueryResult(iter->second, text, sought);
    }
    //// if not use make_shared it will trigge exception in proxy and delete, but don't know why!!!
    ////std::shared_ptr<MAP::iterator> spiter(&iter);
    //std::shared_ptr<MAP::iterator> spiter = make_shared<MAP::iterator>(iter);   
    ////std::shared_ptr<VSTR> spline(&text);                                      
    //std::shared_ptr<VSTR> spline = make_shared<VSTR>(text);
    //QueryResult ret(spiter, spline,flag);
    //return ret;
}

#endif // !_TEXTQUERY_H_