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
		bool flag = false;
		for (auto str : wordvec) {
			if (str == word) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			wordvec.push_back(word);
		}
	}
	std::cout << std::endl;
	std::cout << "word(unique): " << std::endl;
	for (auto str : wordvec) {
		std::cout << str << " ";
	}
	std::cout << std::endl;

	return 0;
}
