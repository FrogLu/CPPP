#pragma once
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
using namespace std;
typedef  double Money;
string bal;
class Account {
public:
	Money balance() {
		return bal;// Õâ¸öbalÊÇprivate Money bal
	}
	void calculate() {
		amount += amount * interestRate;
	}
	static double rate() {
		return interestRate;
	}
	static void rate(double dval);
private:
	Money bal;
	typedef double Money;
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
};
#endif // !_ACCOUNT_H_