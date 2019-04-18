#pragma once
#include "Quote.h"
class Limited_quote :
    public Quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string& bookNo, double p, std::size_t qty, double disc) :
        Quote(bookNo, p), max_qty(qty), discount(disc) {}
    virtual double net_price(std::size_t cnt) const override;
    virtual ~Limited_quote() = default;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

