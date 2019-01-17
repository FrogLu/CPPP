#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/word");
	assert(fin.good());
	fin.tie(&cout);
	std::map<std::string, std::list<int>> wmap;
	unsigned count = 0;
	std::string word;
	while (fin >> word) {
		++count;
		wmap[word].push_back(count);
	}
	for (auto m : wmap) {
		std::cout << "word: " << m.first << " line number: ";
		for (auto i : m.second) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
