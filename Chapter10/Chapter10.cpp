#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Sales_data");
	assert(fin.good());
	fin.tie(&cout);
	std::istream_iterator<Sales_data> isiter(fin), eof;
	std::ostream_iterator<Sales_data> ositer(cout,"\n");
	std::vector<Sales_data> salevec(isiter, eof);
	if (salevec.empty()) {
		std::cerr << "No data!" << std::endl;
		return -1;
	}
	std::sort(salevec.begin(), salevec.end(),compareIsbn);
	for (auto sale : salevec) {
		*ositer++ = sale;
	}
	std::cout << "The sum: " << std::endl;
	auto iter = salevec.begin();
	while (iter != salevec.end()) {
		auto currdata = *iter;
		auto pos = find_if(iter + 1, salevec.end(),
			[currdata](const Sales_data &data1)
			{return data1.isbn() != currdata.isbn(); });
		std::cout << accumulate(iter + 1, pos, currdata) << std::endl;
		iter = pos;
	}

	return 0;
}