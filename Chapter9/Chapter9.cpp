#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	list<int> slist;
	deque<int> ideq1, ideq2;
	int val;
	while (fin >> val) {
		slist.push_front(val);
	}
	for (auto iter = slist.begin(); iter !=slist.end(); ++iter)
	{
		if (*iter % 2 == 0) {
			ideq1.push_back(*iter);
		}
		else {
			ideq2.push_back(*iter);
		}
	}
	cout << "The even numbers are: ";
	for (auto &val : ideq1) {
		cout << val << " ";
	}
	cout << endl;
	cout << "The odd numbers are: ";
	for (auto &val : ideq2) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
