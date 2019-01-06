#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	std::ifstream fin("./data/InputStr");
	assert(!fin.fail());
	fin.tie(&cout);
	std::string str;
	std::vector<std::string> svec;
	while (fin>>str) {
		svec.push_back(str);
	}
	for (auto c : svec) {
		std::cout << c <<" ";
	}
	std::cout << std::endl;

	return 0;
}