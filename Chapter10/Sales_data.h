#pragma once
#ifndef SALES_DATA_H
#define SALES_DATA_H

class Sales_data
{
    // ��Ԫ����
    /*friend Sales_data add(const Sales_data&, const Sales_data&);*/
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    // ���캯��
    //Sales_data() = default;
	// �����������������Ĭ��ʵ�Σ�������������������Ĭ�Ϲ��캯����
	// ��������������Ժ���ʵ�μ�Sales_data()��Ҳ���Լ���ʵ��Sales_data(str).
    /*Sales_data(const std::string &s=" ") :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is);*/
	// ί�й��캯���İ汾
	/*��ί�й��캯��*/
	Sales_data(std::string s, unsigned cnt, double price) :
		bookNo(s), units_sold(cnt), revenue(cnt*price) {
		cout << "This is first constructor" << endl;
	}
	/*���๹�캯��ȫ��ί�и���һ�����캯��*/
	Sales_data() :Sales_data("", 0, 0) {
		cout << "This is first delegating constructor" << endl;
	}
	explicit Sales_data(std::string s) :Sales_data(s, 0, 0) {
		cout << "This is second delegating constructor" << endl;
	}
	explicit Sales_data(std::istream &is) :Sales_data() {
		read(is, *this);
		cout << "This is third delegating constructor" << endl;
	}
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
// inline function
inline double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    else {
        return 0;
    }
}
// Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
#endif // !SALES_DATA_H