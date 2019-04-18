#pragma once
#ifndef _BULK_QUOTE_H_
#define _BULK_QUOTE_H_

#include "Quote.h"
class Bulk_quote :
    public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {}
    virtual double net_price(std::size_t) const override;
    virtual std::ostream& debug(std::ostream& os) const override;
    virtual ~Bulk_quote() = default;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

#endif // !_BULK_QUOTE_H
