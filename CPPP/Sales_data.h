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
    Sales_data() = default;
    Sales_data(const std::string &s) :bookNo(s) {}
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
 //Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif // !SALES_DATA_H
