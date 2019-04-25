#pragma once
#ifndef _BASKET_H_
#define _BASKET_H_

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"

class Basket
{
public:
    Basket()=default;
    void add_item(const std::shared_ptr<Quote>& sale) {
        items.insert(sale);
    }
    void add_item(const Quote& sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote&& sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream&) const;
    virtual ~Basket();
private:
    static bool compare(const std::shared_ptr<Quote>& lhs,
        const std::shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
        items{ compare };
};


inline
Basket::~Basket()
{
}

#endif // !_BASKET_H_