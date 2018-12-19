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

bool process(std::ifstream& ifs,std::vector<string>& vstr) {
	string str;
	if (!ifs.is_open()) {
		return false;
	}
	while (getline(ifs,str)) {
		vstr.push_back(str);
	}
	return true;
}

bool process(std::ofstream& ofs, std::vector<string>& vstr) {
	string str;
	if (!ofs.is_open()) {
		return false;
	}
	for (auto &str : vstr) {
		ofs << str << endl;
	}
	return true;
}

std::vector<int>::iterator myfind(std::vector<int> vint, const int& val) {
	bool flag = false;
	auto it = vint.begin();
	for (; it != vint.end(); ++it) {
		if (flag == false && (*it) == val) {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "The position is " << vint.capacity() << endl;
	}
	else {
		cout << "Can't find the same value in the containter, "
			<< "return the end of iterator" << endl;
	}
	return vint.end();
}


