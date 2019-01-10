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
	std::list<std::string> slst;
	std::list<std::string> uslst;
	copy(svec.cbegin(), svec.cend(), back_inserter(slst));
	//copy(svec.cbegin(), svec.cend(), front_inserter(slst));
	//copy(svec.cbegin(), svec.cend(), inserter(slst,slst.end()));
	unique_copy(svec.cbegin(), svec.cend(), back_inserter(uslst));
	//unique_copy(svec.cbegin(), svec.cend(), front_inserter(uslst));
	//unique_copy(svec.cbegin(), svec.cend(), inserter(uslst, uslst.end()));

	/* Output */
	std::cout << "This is slst member: " << std::endl;
	for (auto c : slst) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	std::cout << "This is uslst member: " << std::endl;
	for (auto c : uslst) {
		std::cout << c << " ";
	}

	return 0;
}