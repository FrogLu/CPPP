#include "pch.h"
#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty) {
        return cnt * (1 - discount) * price;
    }
    else {
        return cnt * price;
    }
}

std::ostream& Bulk_quote::debug(std::ostream& os) const
{
    return Quote::debug(os) << " min_qty: " << min_qty << " discount: " << discount;
}

Bulk_quote::~Bulk_quote()
{
    std::cout << "Bulk_quote::~Bulk_quote()" << std::endl;
}
