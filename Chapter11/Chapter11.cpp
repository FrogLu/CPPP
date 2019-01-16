#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/Str");
	assert(fin.good());
	fin.tie(&cout);
	std::map<std::string, std::size_t> word_count;
	std::set<std::string> exclude = { "bad","red","rrr" };
	std::string word;
	std::cout << "Origin: " << std::endl;
	while (fin >> word) {
		std::cout << word << " ";
		if (exclude.find(word) == exclude.cend()) {
			++word_count[word];
		}
	}
	std::cout << std::endl;
	std::cout << "Count result: " << std::endl;
	for (const auto &w : word_count) {
		std::cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? "times" : "time") << std::endl;
	}

	return 0;
}
