#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/word");
	assert(fin.good());
	fin.tie(&cout);
	std::map<std::string, std::size_t>word_count;
	std::set<std::string> exclude = { "hello" };
	std::string word;
	while (fin >> word) {
		if (exclude.find(word) == exclude.end()) {
			auto piter=word_count.insert({ word,1 });
			if (!piter.second) {
				++(*piter.first).second;	// piter is a pair, piter.first is a iterator
			}
		}
	}
	for (auto p : word_count) {
		std::cout << p.first << " " << p.second << std::endl;
	}

	return 0;
}
