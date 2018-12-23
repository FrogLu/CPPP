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
	cout << "The raw data is ";
	for (auto &val : ivec) {
		cout << val << " ";
	}
	cout << endl;
	std::vector<int>::iterator iter = ivec.begin(),
		mid = ivec.begin() + ivec.size() / 2;
	while (iter != (ivec.begin()+ivec.size()/2)) {
		if (*iter == some_val) {
			iter=ivec.insert(iter, 2 * some_val);
			++iter;
			++iter;
			cout << *iter << endl;
		}
		else {
			++iter;
		}
	}
	return 0;
}
