#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	std::ifstream fin("./data/InputStr");
	assert(!fin.fail());
	fin.tie(&cout);
	string str;
	vector<string> svec;
	while (fin>>str) {
		svec.push_back(str);
	}
	for (auto c : svec) {
		cout << c <<" ";
	}
	cout << endl;
	auto iter=partition(svec.begin(), svec.end(), stringgeq5);
	for (auto c : svec) {
		cout << c << " ";
	}
	cout << endl;
	while (iter != svec.end()) {
		cout << *iter << " ";
		++iter;
	}
	cout << endl;
	return 0;
}