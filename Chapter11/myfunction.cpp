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