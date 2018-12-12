#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
//using namespace std;
class Sales_data
{
    // 友元函数
    /*friend Sales_data add(const Sales_data&, const Sales_data&);*/
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    // 构造函数
    //Sales_data() = default;
	// 下面这个函数设置了默认实参，所以其包含了上面这个默认构造函数。
	// 下面这个函数可以忽略实参即Sales_data()，也可以加入实参Sales_data(str).
    Sales_data(const std::string &s=" ") :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is);
    // 成员函数
    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    // 数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double sellingprice = 0.0;//原价
    double saleprice = 0.0;//实售价
    double discount = 0.0;//折扣
    // 成员函数
    double avg_price() const;
};
// inline function
inline double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    else {
        return 0;
    }
}
// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif // !SALES_DATA_H