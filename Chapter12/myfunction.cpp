#include "pch.h"
#include "myfunction.h"

std::vector<int>* Foo() {
	auto* p = new std::vector<int>;
	return p;
}

std::vector<int>* InputFoo(std::istream& is,std::vector<int>* pivec) {
	int val;
	while (is >> val) {
		(*pivec).push_back(val);
	}
	return pivec;
}

void OutputFoo(std::ostream& os, std::vector<int> *pivec) {
	for (auto i : (*pivec)) {
		os << i << " ";
	}
	os << std::endl;
	delete pivec;
}