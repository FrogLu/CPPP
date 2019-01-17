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
	std::map<std::string, std::vector<std::pair<std::string,std::string>>>&families) {
	std::string line;
	while (getline(is, line)) {
		std::istringstream istr(line);
		std::string name;
		std::pair<std::string,std::string> child;
		istr >> name;
		while (istr >> child.first>>child.second) {
			families[name].push_back(child);
		}
	}
}

void pairprint(std::map<std::string, std::vector<std::pair<std::string, std::string>>>&families) {
	for (auto f : families) {
		std::cout << "family: " << f.first;
		for (auto p : f.second) {
			std::cout << " name: " << p.first
				<< " birthday: " << p.second;
		}
		std::cout << std::endl;
	}
}