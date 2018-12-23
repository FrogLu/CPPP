#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	list<string> slist;
	string str;
	while (fin >> str) {
		slist.push_front(str);
	}
	for (auto iter = slist.begin(); iter !=slist.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
