#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/families");
	assert(fin.good());
	fin.tie(&cout);
	std::pair<std::string, int> sipair;
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
	addfamily(fin, families);
	pairprint(families);

	return 0;
}
