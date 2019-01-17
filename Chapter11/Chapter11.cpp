#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/str");
	assert(fin.good());
	fin.tie(&cout);
	std::pair<std::string, int> sipair;
	std::vector<std::pair<std::string, int>> pvec;
	while (fin >> sipair.first >> sipair.second) {
		pvec.push_back(sipair);
	}
	for (auto p : pvec) {
		std::cout << p.first << " " << p.second << std::endl;
	}

	return 0;
}
