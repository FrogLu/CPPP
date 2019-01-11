#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/InputStr");
	assert(fin.good());
	fin.tie(&cout);
	std::istream_iterator<string> isiter(fin), eof;
	std::vector<std::string> svec(isiter, eof);
	for (auto c : svec) {
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}