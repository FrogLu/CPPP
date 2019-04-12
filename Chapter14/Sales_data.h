#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H

class Sales_data
{
    // friend function
	friend std::ostream &operator<<(std::ostream & os, const Sales_data & data);
	friend std::istream &operator>>(std::istream & is, Sales_data & data);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
    friend Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
public:
    // constructor
	Sales_data(std::string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt*price) {}
	// Delegate constructor 
	Sales_data() :Sales_data("", 0, 0) {}
    explicit Sales_data(std::string s) :Sales_data(s, 0, 0) {}
	explicit Sales_data(std::istream &is) :Sales_data() {is >> (*this);}
    // user function
    std::string isbn() const { return this->bookNo; }
    Sales_data operator+=(const Sales_data& rhs);
    Sales_data operator-=(const Sales_data& rhs);
private:
    // data
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double sellingprice = 0.0;  //  Original price
    double saleprice = 0.0; //  Actual selling price
    double discount = 0.0;
    // function
    double avg_price() const;
};
// inline function
inline 
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    else {
        return 0;
    }
}
// non-member function
std::ostream &operator<<(std::ostream & os, const Sales_data & data);
std::istream &operator>>(std::istream & is, Sales_data & data);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
#endif // !SALES_DATA_H