#include "pch.h"
#include "Sales_data.h"

std::ostream &operator<<(std::ostream& os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price() << " "
        << item.saleprice;

    return os;
}

std::istream & operator>>(std::istream & is, Sales_data & item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is.good()) {
        item.revenue = item.units_sold * price;
    }
    else {
        item = Sales_data();
    }

    return is;
}

Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;

    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    *this = (*this) + rhs;

    return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs) {
    try {
        if (units_sold < rhs.units_sold || revenue < rhs.revenue) {
            throw std::range_error("Error: the result of units sold price is less than zero.");
        }
    }
    catch (std::range_error valueErr) {
        std::cout << valueErr.what() << std::endl;
    }
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;

    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) 
{
    Sales_data sum = lhs;
    sum.units_sold += rhs.units_sold;
    sum.revenue +=  rhs.revenue;

    return sum;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum(lhs);

    return sum -= rhs;
}