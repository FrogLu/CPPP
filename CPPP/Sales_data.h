#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H
//using namespace std;
class Sales_data
{
    // ��Ԫ����
    /*friend Sales_data add(const Sales_data&, const Sales_data&);*/
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    // ���캯��
    Sales_data() = default;
    Sales_data(const std::string &s) :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is);
    // ��Ա����
    std::string isbn() const { return this->bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    // ���ݳ�Ա
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double sellingprice = 0.0;//ԭ��
    double saleprice = 0.0;//ʵ�ۼ�
    double discount = 0.0;//�ۿ�
    // ��Ա����
    double avg_price() const;
};
 //Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif // !SALES_DATA_H
