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
	int val;
	cin >> val;
	assert(cin.good());
	auto f = [val]() mutable ->bool {
		val > 0 ? --val : val;
		return val > 0 ? false : true; };
	for (auto temp = val; temp > 0;--temp) {
		std::cout << "The value is: " << val << std::endl;
		std::cout << std::boolalpha << f() << std::endl;
	}

	return 0;
}