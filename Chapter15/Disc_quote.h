#pragma once
#include "Quote.h"
class Disc_quote :
    public Quote
{
public:
    //Disc_quote() = default;   //  comment this constructor, and I declarate another constructor,
    //                          //  then this constructor won't be created by compiler, throw E1790
    Disc_quote(const std::string& book, double price,
        std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t)const override = 0 ;
    virtual ~Disc_quote();
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

