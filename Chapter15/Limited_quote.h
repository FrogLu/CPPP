#pragma once
#include "Disc_quote.h"
class Limited_quote :
    public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string& bookNo, double p, std::size_t qty, double disc) :
        Disc_quote(bookNo, p, qty, disc) {}
    virtual double net_price(std::size_t cnt) const override;
    virtual std::ostream& debug(std::ostream& os) const override;
    virtual ~Limited_quote() = default;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

