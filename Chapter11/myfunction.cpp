#include "pch.h"
#include "myfunction.h"

std::string wordprocess(const std::string &word) {
	string procword;
	if (word[word.size()-1] == '.') {
		procword.assign(word.cbegin(), word.cend() - 1);
	}
	else {
		procword = word;
	}
	for (auto &c : procword) {
		c=tolower(c);
	}
	return procword;
}

void addfamily(std::istream&is, 
	std::map<std::string, std::vector<std::string>>&family) {
	std::string line;
	while (getline(is, line)) {
		std::istringstream istr(line);
		std::string name, child;
		istr >> name;
		while (istr >> child) {
			family[name].push_back(child);
		}
	}
}	