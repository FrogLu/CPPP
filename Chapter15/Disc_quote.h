#pragma once
#ifndef _DISC_QUOTE_H_
#define _DISC_QUOTE_H_

#include "Quote.h"
class Disc_quote :
    public Quote
{
public:
    Disc_quote() = default;   //  comment this constructor, and I declare another constructor,
                              //  then this constructor won't be created by compiler, throw E1790
    Disc_quote(const std::string& book, double price,
        std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {}
    Disc_quote(const Disc_quote&);
    Disc_quote(Disc_quote&&)noexcept;
    Disc_quote& operator=(const Disc_quote&);
    Disc_quote& operator=(Disc_quote&&)noexcept;
    double net_price(std::size_t)const override = 0;    //  it (a pure virtual) 
                                                        //  cause Disc_quote is an abstract class type
    virtual ~Disc_quote();
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

inline
Disc_quote::Disc_quote(const Disc_quote& dsqt) :
    Quote(dsqt)
{
    quantity = dsqt.quantity;
    discount = dsqt.discount;

    std::cout << "Disc_quote::Disc_quote(const Disc_quote& dsqt)" << std::endl;
}

inline
Disc_quote::Disc_quote(Disc_quote&& dsqt)noexcept :
    Quote(std::move(dsqt))
{
    quantity = std::move(dsqt.quantity);
    discount = std::move(dsqt.discount);

    std::cout << "Disc_quote::Disc_quote(Disc_quote&& dsqt)" << std::endl;
}

inline 
Disc_quote& Disc_quote::operator=(const Disc_quote& rhs)
{
    Quote::operator=(rhs);

    quantity = rhs.quantity;
    discount = rhs.discount;

    std::cout << "Disc_quote::operator=(const Disc_quote& rhs)" << std::endl;

    return *this;
}

inline
Disc_quote& Disc_quote::operator=(Disc_quote&& rhs)noexcept
{
    Quote::operator=(rhs);

    quantity = std::move(rhs.quantity);
    discount = std::move(rhs.discount);

    std::cout << "Disc_quote::operator=(Disc_quote&& rhs)" << std::endl;

    return *this;
}

#endif // !_DISC_QUOTE_H_