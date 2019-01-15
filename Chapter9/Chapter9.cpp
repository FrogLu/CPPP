#include "pch.h"
#include "myfunction.h"
#include "mydate.h"

int main()
{
	std::ifstream finstr("inputstr.txt");
	assert(finstr.good());
	finstr.tie(&cout);
	string str;
	vector<string> svec;
	mydate date;
	while (getline(finstr,str)) {
		svec.push_back(str);
	}
	for (auto str : svec) {
		std::cout << str << " ";
	}
	std::cout << std::endl;
	for (auto str : svec) {
		date.stringtodate(str); 
		cout << date;
	}
	return 0;
}
