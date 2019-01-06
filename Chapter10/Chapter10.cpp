#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Sales_data");
	assert(!fin.fail());
	fin.tie(&cout);
	Sales_data sd;
	std::vector<Sales_data> sdvec;
	while (read(fin,sd)) {
		sdvec.push_back(sd);
	}
	for (auto c : sdvec) {
		print(cout, c);
		cout << endl;
	}
	std::cout << std::endl;
	/* fin done */
	std::sort(sdvec.begin(), sdvec.end(),
		[](Sales_data&sd1, Sales_data&sd2) {return sd1.isbn() < sd2.isbn(); });
	cout << "sorted:" << endl;
	for (auto c : sdvec) {
		print(cout, c);
		cout << endl;
	}
	std::cout << std::endl;
	return 0;
}