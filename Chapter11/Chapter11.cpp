#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/str");
	assert(fin.good());
	fin.tie(&cout);
	std::vector<std::string> wordvec;
	std::string word;
	std::cout << "Origin: " << std::endl;
	while (fin >> word) {
		std::cout << word << " ";
		wordvec.push_back(word);
	}
	std::sort(wordvec.begin(), wordvec.end());	// sorted before unique can obtain
												// O(nlogn) for worst situation.
	auto iter = std::unique(wordvec.begin(), wordvec.end());
	wordvec.erase(iter, wordvec.end());
	std::cout << std::endl;
	std::cout << "word(unique): " << std::endl;
	for (auto str : wordvec) {
		std::cout << str << " ";
	}
	std::cout << std::endl;

	return 0;
}
