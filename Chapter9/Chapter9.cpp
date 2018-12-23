#include "pch.h"
#include <iostream>
using namespace std;
#define some_val 3
int main()
{
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	vector<int> ivec;
	list<int> ilist;
	int val;
	while (fin >> val) {
		ivec.push_back(val);
	}
	ilist.assign(ivec.begin(),ivec.end());
	auto liter = ilist.begin();
	cout << "list: ";
	for (auto liter = ilist.begin(); liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl;
	cout << "vector: ";
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	liter = ilist.begin();
	for (auto iter = ivec.begin(); iter != ivec.end(); )
	{
		if (*iter & 1) {
				liter = ilist.erase(liter);
				++iter;
		}
		else {
				iter = ivec.erase(iter);
				++liter;
		}
	}
	cout << "list: ";
	for (auto liter = ilist.begin(); liter != ilist.end(); ++liter)
	{
		cout << *liter << " ";
	}
	cout << endl;
	cout << "vector: ";
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
