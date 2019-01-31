#include "pch.h"
#include "myfunction.h"

std::vector<int>* Foo() {
	return new (std::nothrow) std::vector<int>;
}

void InputFoo(std::istream& is, std::vector<int>* pivec) {
	int val;
	while (is >> val) {
		(*pivec).push_back(val);
	}
}

void OutputFoo(std::ostream& os, std::vector<int>* pivec) {
	for (auto i : (*pivec)) {
		os << i << " ";
	}
	os << std::endl;
}