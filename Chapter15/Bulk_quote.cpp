#include "pch.h"
#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t cnt) const
{
    std::cout << "Bulk_quote::net_price(std::size_t cnt) called" << std::endl;
    if (cnt >= quantity) {
        return cnt * (1 - discount) * price;
    }
    else {
        return cnt * price;
    }
}

std::ostream& Bulk_quote::debug(std::ostream& os) const
{
    return Quote::debug(os) << " min_qty: " << quantity << " discount: " << discount;
}

Bulk_quote::~Bulk_quote()
{
    std::cout << "Bulk_quote::~Bulk_quote()" << std::endl;
}
