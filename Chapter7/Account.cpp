#include "stdafx.h"
#include "Account.h"
// static member
#define currentInterestRate 2.3*0.01
double Account::interestRate = initRate();
double Account::initRate() {
	return currentInterestRate;
}
void Account::rate(double newRate) {
	interestRate = newRate;
}