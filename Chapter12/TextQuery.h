#pragma once
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "StrBlob.h"

void runQueries(std::ifstream& infile);
class QueryResult;
class TextQuery {
    friend class QueryResult;
public:
    using line_no=StrBlob::size_type;
    //typedef std::vector<std::string>::size_type SVST;
    typedef StrBlob  VSTR;
    typedef std::map<std::string, std::shared_ptr<std::set<line_no> > > MAP;
    TextQuery() = default;
    TextQuery(const VSTR& svec, const MAP& rowcount) :file(svec), wm(rowcount) {};
    TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& str);
    void display_map(); // for debugging
private:
    VSTR file;
    MAP wm;
    static std::string cleanup_str(const std::string& word);
};
inline
TextQuery::TextQuery(std::ifstream& infile):file(new std::vector<std::string>) {
    std::string linestr;
    
    while (std::getline(infile, linestr)) {
        
        file.push_back(linestr);
        line_no count = file.size() - 1;
        std::istringstream line(linestr);
        std::string word;
        while (line >> word) {
            //rowMap[word].insert(count);
            auto& lines = wm[word];
            if (!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(count);
        }
    }
}

class QueryResult {
    
    friend std::ostream& print(std::ostream& out, const QueryResult& result);
public:
    typedef std::shared_ptr<std::set<TextQuery::line_no> > SP;
    typedef StrBlobPtr SVS;
    QueryResult() = default;
    QueryResult(SP sp, SVS curr,const std::string sg) :lines(sp), files(curr),sought(sg) {};
    std::set<TextQuery::line_no>::iterator begin();
    const std::set<TextQuery::line_no>::iterator begin()const;
    std::set<TextQuery::line_no>::iterator end();
    const std::set<TextQuery::line_no>::iterator end()const;
    StrBlobPtr get_spline() { return files; }
private:
    SP lines;
    SVS files;
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
    out << result.sought << " occurs " << result.lines->size() << " "
        << make_plural(result.lines->size(), "time", "s") << std::endl;
    for (auto num : *result.lines) {
        out << "\t(line " << num + 1 << ") "
            << result.files.deref(num) << std::endl;
    }
    return out;
}

inline
QueryResult TextQuery::query(const std::string& sought)
{
    static std::shared_ptr<std::set<line_no> > nodata;
    auto iter = wm.find(sought);
    if (iter == wm.cend()) {
        return QueryResult(nodata,file,sought);
    }
    else {
        return QueryResult(iter->second, file, sought);
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