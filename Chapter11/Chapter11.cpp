#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/family");
	assert(fin.good());
	fin.tie(&cout);
	std::map<std::string, std::vector<std::string>> familymap;
	addfamily(fin, familymap);
	for (auto f : familymap) {
		std::cout << "Family: " << f.first << " member: ";
		for (auto m : f.second) {
			std::cout << m << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
