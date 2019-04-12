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
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> item.saleprice;
    item.revenue = item.saleprice * item.units_sold;

    return is;
}

Sales_data Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data Sales_data::operator-=(const Sales_data& rhs) {
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

    return sum += rhs;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum(lhs);

    return sum -= rhs;
}