#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/InputStr");
	assert(fin.good());
	fin.tie(&cout);
	std::string str;
	std::vector<std::string> svec;
	while (fin>>str) {
		svec.push_back(str);
	}
	for (auto c : svec) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	/* fin done */
	std::list<int> ilst1, ilst2, ilst3;
	std::vector<int> ivec;
	for (auto count = 1; count != 10; ++count) {
		ivec.push_back(count);
	}
	std::copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst1));
	std::copy(ivec.cbegin(), ivec.cend(), inserter(ilst2,ilst2.end()));
	std::copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst3));
	/* Output */
	std::cout << "ilst1 members: " << std::endl;
	for (auto val : ilst1) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	std::cout << "ilst2 members: " << std::endl;
	for (auto val : ilst2) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	std::cout << "ilst3 members: " << std::endl;
	for (auto val : ilst3) {
		std::cout << val << " ";
	}

	return 0;
}