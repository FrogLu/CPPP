#pragma once
#ifndef _QUERY_H_
#define _QUERY_H_


class Query_base
{
    friend class Query;
protected:
    using line_no=TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};


class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&,const Query&);
    friend Query operator&(const Query&,const Query&);
    friend std::ostream& operator<<(std::ostream&, const Query&);
public:
    Query(const std::string& s);
    QueryResult eval(const TextQuery& t)const {
        return q->eval(t);
    }
    std::string rep() const {
        return q->rep();
    }
private:
    Query(std::shared_ptr<Query_base> query) :q(query) {}
    std::shared_ptr<Query_base> q;
};


std::ostream&
operator<<(std::ostream& os, const Query& query)
{
    return os << query.rep();
}


class WordQuery :public Query_base {
    friend class Query;
    WordQuery(const std::string& s) :query_word(s) {}
    QueryResult eval(const TextQuery& t)const override {
        return t.query(query_word);
    }
    std::string rep()const override {
        return query_word;
    }
    std::string query_word;
};


//  This constructor must declare here, 
//  because this constructor use WordQuery to init itself.
//  So must after class Query defined.
inline
Query::Query(const std::string& s) :q(new WordQuery(s)) {
    /*void*/
}


class NotQuery :public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q):query(q){}

    std::string rep() const override {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery&)const override ;
    Query query;
};


inline
Query operator~(const Query& operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


class BinaryQuery :public Query_base {
protected:
    BinaryQuery(const Query&l,const Query&r,std::string s):
        lhs(l),rhs(r),opSym(s){/*void*/}

    std::string rep() const override{
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};


class AndQuery :public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right) :
        BinaryQuery(left, right, "&") {/*void*/}

    QueryResult eval(const TextQuery&)const;
};

inline
Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


class OrQuery :public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right) :
        BinaryQuery(left, right, "|") {/*void*/}
    QueryResult eval(const TextQuery&)const;
};

inline
Query operator|(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif // !_QUERY_H_