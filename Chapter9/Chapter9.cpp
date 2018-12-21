#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	std::ifstream fin1("input1.txt");
	std::ifstream fin2("input2.txt");
	fin1.tie(&cout);
	fin2.tie(&cout);
	vector<int> ivec1;
	vector<int> ivec2;
	int val1, val2;
	while (fin1 >> val1) {
		ivec1.push_back(val1);
	}
	while (fin2 >> val2) {
		ivec2.push_back(val2);
	}
	if (ivec1 == ivec2) {
		cout << std::boolalpha << true << endl;
	}
	else {
		cout << std::boolalpha << false << endl;
	}

	return 0;
}
