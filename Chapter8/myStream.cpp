#include "pch.h"
#include "myStream.h"
std::istream& myprint(std::istream& is) {
	auto old_state = is.rdstate();
	int val;
	while (is >> val, !is.eof()) {
		if (is.bad()) {
			throw runtime_error("IO stream wrong!");
		}
		if(is.fail()) {
			cerr << "date wrong, please enter correct number again:" << endl;
			is.clear(old_state);
			is.ignore(100, '\n');
			continue;	// ±ÜÃâÖ´ÐÐcout<<val<<endl
		}
		cout << val << endl;
	}
	is.clear(old_state);
	return is;
}

