#include "pch.h"
#include "Quote.h"


std::ostream& Quote::debug(std::ostream& os) const
{
    return os << "bookNo: " << bookNo << " # " << "price: " << price;
}

Quote::~Quote()
{
    std::cout << "Quote::~Quote()" << std::endl;
}

//  non-member function
double print_total(std::ostream& os, const Quote& item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}