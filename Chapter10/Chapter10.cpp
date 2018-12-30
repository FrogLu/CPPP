#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	std::ifstream fin("./data/Sales_data");
	assert(!fin.fail());
	fin.tie(&cout);
	Sales_data sd;
	vector<Sales_data> sdvec;
	while (read(fin, sd)) {
		sdvec.push_back(sd);
	}
	for (auto c : sdvec) {
		print(cout, c);
		cout << endl;
	}
	cout << endl;
	sort(sdvec.begin(), sdvec.end(), compareIsbn);
	for (auto c : sdvec) {
		print(cout, c);
		cout << endl;
	}
	return 0;
}