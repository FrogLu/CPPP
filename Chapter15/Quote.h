#pragma once
#ifndef _QUOTE_H_
#define _QUOTE_H_

class Quote
{
public:
    Quote() = default;
    Quote(const std::string& book,double sales_price):
        bookNo(book),price(sales_price){}
    Quote(const Quote&);
    Quote(Quote&&)noexcept;
    Quote& operator=(const Quote&);
    Quote& operator=(Quote&&)noexcept;
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n)const { return n * price; }
    virtual std::ostream& debug(std::ostream& os) const;
    virtual ~Quote();
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

inline
Quote::Quote(const Quote& qt) {
    bookNo = qt.bookNo;
    price = qt.price;

    std::cout << "Quote::Quote(const Quote& qt)" << std::endl;
}

inline 
Quote::Quote(Quote&& qt)noexcept
{
    bookNo = std::move(qt.bookNo);
    price = std::move(qt.price);

    std::cout << "Quote::Quote(Quote&& qt)" << std::endl;
}

inline 
Quote& Quote::operator=(const Quote& rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;

    std::cout << "Quote::operator=(const Quote& rhs)" << std::endl;

    return *this;
}

inline 
Quote& Quote::operator=(Quote&& rhs)noexcept
{
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);

    std::cout << "Quote::operator=(Quote&& rhs)" << std::endl;

    return *this;
}

// non-member function
double print_total(std::ostream& os, const Quote& item, std::size_t n);

#endif // !_QUOTE_H_

