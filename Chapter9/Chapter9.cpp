#include "pch.h"
#include <iostream>
using namespace std;
#define some_val 3
int main()
{
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	vector<int> ivec;
	deque<int> ideq1, ideq2;
	int val;
	while (fin >> val) {
		ivec.push_back(val);
	}
	// ����ڿ����������л��׳�out_of_range�쳣
	if (!ivec.empty()) {
		cout << "The first member(at): " << ivec.at(0) << endl;
		cout << "The first member(subscript): " << ivec[0] << endl;
		cout << "The first member(front()): " << ivec.front() << endl;
		cout << "The first member(begin()): " << *ivec.begin() << endl;
	}
	return 0;
}
