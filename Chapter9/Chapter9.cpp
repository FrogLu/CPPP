#include "pch.h"
#include "myfunction.h"
#include <iostream>
using namespace std;
int main()
{
	list<int> ilist(10, 42);
	cout << "first: ";
	for (auto &val : ilist) {
		cout << val << " ";
	}
	cout << endl;
	ilist.resize(15);
	cout << "second: ";
	for (auto &val : ilist) {
		cout << val << " ";
	}
	cout << endl;
	ilist.resize(25, -1);
	cout << "third: ";
	for (auto &val : ilist) {
		cout << val << " ";
	}
	cout << endl;
	ilist.resize(5);
	cout << "forth: ";
	for (auto &val : ilist) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
