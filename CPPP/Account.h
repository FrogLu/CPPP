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
		return bal;// ���bal��private Money bal
	}
private:
	Money bal;
	typedef double Money;
};
#endif // !_ACCOUNT_H_