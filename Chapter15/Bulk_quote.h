#pragma once
#ifndef _BULK_QUOTE_H_
#define _BULK_QUOTE_H_

#include "Disc_quote.h"
class Bulk_quote :
    public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
        Disc_quote(book, p,qty,disc) {}
    virtual double net_price(std::size_t) const override;
    virtual std::ostream& debug(std::ostream& os) const override;
    virtual ~Bulk_quote() = default;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

#endif // !_BULK_QUOTE_H
