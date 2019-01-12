#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/InputInt");
	std::ofstream fout1("./data/Output1", std::ostream::app);
	std::ofstream fout2("./data/Output2", std::ostream::app);
	assert(fin.good());
	assert(fout1.good());
	assert(fout2.good());
	fin.tie(&cout);
	std::istream_iterator<int> isiter(fin), eof;
	std::ostream_iterator<int> ositer1(fout1, " "), ositer2(fout2, "\n");
	while (isiter != eof) {
		(*isiter) % 2 ? ositer1 = *isiter : ositer2 = *isiter;
		++isiter;
	}

	return 0;
}