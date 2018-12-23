#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	deque<string> sdeq;
	string str;
	while (fin >> str) {
		sdeq.push_front(str);
	}
	for (auto iter = sdeq.begin(); iter !=sdeq.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
