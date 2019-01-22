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

void word_transform(std::ifstream &map_file, std::ifstream &input) {
	auto trans_map = buildMap(map_file);
	std::string text;
	while (getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;	//control whether print whitespace
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			}
			else {
				std::cout << " ";
			}
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

ssumultimap buildMap(std::ifstream &map_file) {
	ssumultimap trans_map;
	std::string key;
	std::string mapped;
	while (map_file >> key && getline(map_file, mapped)) {
		if (mapped.size() > 1) {
			trans_map[key] = mapped.substr(1);
		}
		else {
			throw std::runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}

const std::string & transform(const std::string &s,
	const ssumultimap &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend()) {
		return map_it->second;
	}
	else {
		return s;
	}
}