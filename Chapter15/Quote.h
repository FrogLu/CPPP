#pragma once
#ifndef _QUOTE_H_
#define _QUOTE_H_

class Quote
{
public:
    Quote() = default;
    Quote(const std::string& book,double sales_price):
        bookNo(book),price(sales_price){}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n)const { return n * price; }
    virtual std::ostream& debug(std::ostream& os) const;
    virtual ~Quote();
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

// non-member function
double print_total(std::ostream& os, const Quote& item, std::size_t n);

#endif // !_QUOTE_H_

