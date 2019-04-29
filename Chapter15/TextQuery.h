#pragma once
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "StrBlob.h"
#include "myfunction.h"

void runQueries(std::ifstream& infile);
class QueryResult;
class TextQuery {
    friend class QueryResult;
public:
    using line_no=std::vector<std::string>::size_type;
    //typedef std::vector<std::string>::size_type SVST;
    typedef std::shared_ptr<std::vector<std::string>>  VSTR;
    typedef std::map<std::string, std::shared_ptr<std::set<line_no> > > MAP;
    TextQuery() = default;
    TextQuery(const VSTR& svec, const MAP& rowcount) :file(svec), wm(rowcount) {};
    TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& str);
    QueryResult query(const std::string& str)const;
    void display_map(); // for debugging
private:
    VSTR file;
    MAP wm;
    static std::string cleanup_str(const std::string& word);
};
inline
TextQuery::TextQuery(std::ifstream& infile):file(new std::vector<std::string>) {
    char ws[] = { '\t','\r','\v','\f','\n' };
    char eos[] = { '?','.','!' };
    std::set<char> whiteSpace(ws, ws + 5);
    std::set<char> endOfSentence(eos, eos + 3);
    std::string sentence;
    char ch;
    
    while (infile.get(ch)) {
        if (!whiteSpace.count(ch)) {
            sentence += ch;
        }
        if(endOfSentence.count(ch)) {
            file->push_back(sentence);
            line_no count = file->size() - 1;
            std::istringstream line(sentence);
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
        sentence.assign("");    //  clear sentence
    }
}

class QueryResult {
    
    friend std::ostream& operator<<(std::ostream& out, const QueryResult& result);
public:
    typedef std::shared_ptr<std::set<TextQuery::line_no> > SP;
    typedef std::shared_ptr<std::vector<std::string>> SVS;
    QueryResult() = default;
    QueryResult(SP sp, SVS curr,const std::string sg) :lines(sp), files(curr),sought(sg) {};
    std::set<TextQuery::line_no>::iterator begin();
    const std::set<TextQuery::line_no>::iterator begin()const;
    std::set<TextQuery::line_no>::iterator end();
    const std::set<TextQuery::line_no>::iterator end()const;
    SVS get_file() { return files; }
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
        std::cout << tq.query(str) << std::endl;
    }
}

inline
std::ostream& operator<<(std::ostream& out, const QueryResult& result)
{
    out << result.sought << " occurs " << result.lines->size() << " "
        << make_plural(result.lines->size(), "time", "s") << std::endl;
    for (auto num : *result.lines) {
        out << "\t(line " << num + 1 << ") "
            << (*result.files)[num] << std::endl;
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
    //// if not use make_shared it will trigger exception in proxy and delete, but don't know why!!!
    ////std::shared_ptr<MAP::iterator> spiter(&iter);
    //std::shared_ptr<MAP::iterator> spiter = make_shared<MAP::iterator>(iter);   
    ////std::shared_ptr<VSTR> spline(&text);                                      
    //std::shared_ptr<VSTR> spline = make_shared<VSTR>(text);
    //QueryResult ret(spiter, spline,flag);
    //return ret;
}

inline
QueryResult TextQuery::query(const std::string& str)const {
    return (const_cast<TextQuery*>(this))->query(str);
}

#endif // !_TEXTQUERY_H_