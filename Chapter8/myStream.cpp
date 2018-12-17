#include "pch.h"
#include "myStream.h"
std::istream& myprint(std::istream& is) {
	auto old_state = is.rdstate();
	while (!is.eof()) {
		string str;
		is >> str;
		cout << str;
	}
	is.clear(old_state);
	return is;
}

