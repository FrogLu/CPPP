#include "pch.h"
#include "myfunction.h"

shared_ptr<vector<int>> Foo() {
	shared_ptr<vector<int>> p = std::make_shared<vector<int>>();
	return p;
}

shared_ptr<vector<int>> InputFoo(std::istream& is, shared_ptr<vector<int>> pivec) {
	int val;
	while (is >> val) {
		(*pivec).push_back(val);
	}
	return pivec;
}

void OutputFoo(std::ostream& os, shared_ptr<vector<int>> pivec) {
	for (auto i : (*pivec)) {
		os << i << " ";
	}
	os << std::endl;
	/*delete pivec;*/
}