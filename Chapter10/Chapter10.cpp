#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/InputStr");
	assert(fin.good());
	fin.tie(&cout);
	std::istream_iterator<std::string> isiter(fin), eof;
	std::ostream_iterator<std::string> ositer(cout, " ");
	std::list<std::string> slst(isiter,eof);
	std::cout << "Origin: " << std::endl;
	for (auto c : slst) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	elimDups_list(slst);
	std::cout << "After sorted unique: " << std::endl;
	for (auto c : slst) {
		std::cout << c << " ";
	}
	std::cout << std::endl;

	return 0;
}