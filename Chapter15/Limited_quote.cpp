#include "pch.h"
#include "Limited_quote.h"

double Limited_quote::net_price(std::size_t cnt) const
{
    if (cnt <= max_qty) {
        return cnt * (1 - discount) * price;
    }
    else {
        return (max_qty * (1 - discount) * price) + ((cnt - max_qty) * price);
    }
}

std::ostream& Limited_quote::debug(std::ostream& os) const
{
    return Quote::debug(os) << " max_qty: " << max_qty << " discount: " << discount;
}
