#include "pch.h"
#include "Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}
//非成员函数
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> item.saleprice;
    item.revenue = item.saleprice*item.units_sold;

    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price() << " "
        << item.saleprice;

    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

std::ostream &operator<<(std::ostream& os, const Sales_data &data) {
	return print(os, data);
}

std::istream & operator>>(std::istream & is, Sales_data & data)
{
	return read(is, data);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	return add(lhs, rhs);
}