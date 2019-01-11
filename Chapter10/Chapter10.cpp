#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/InputInt");
	assert(fin.good());
	fin.tie(&cout);
	std::istream_iterator<int> isiter(fin), eof;
	std::ostream_iterator<int> ositer(cout," ");
	std::vector<int> ivec(isiter, eof);
	std::sort(ivec.begin(), ivec.end());
	std::copy(ivec.begin(), ivec.end(), ositer);

	return 0;
}