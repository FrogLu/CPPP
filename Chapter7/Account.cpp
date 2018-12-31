#include "stdafx.h"
#include "Account.h"
// static member
double Account::interestRate = initRate();
double Account::initRate() {
	const double currentInterestRate = 2.3*0.01;
	return currentInterestRate;
}
void Account::rate(double newRate) {
	interestRate = newRate;
}