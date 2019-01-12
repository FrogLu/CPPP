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
	std::list<int> ilst(isiter, eof);
	for (auto val : ilst) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	const int number = 9;
	auto last_z = find(ilst.crbegin(), ilst.crend(), number);
	int pos = 0;
	for (auto iter = ilst.cbegin(); iter != last_z.base(); ++iter, ++pos);
	if (!pos) {
		std::cout << "Can't find number " << number << " in container" << std::endl;
	}
	else {
		std::cout << "last pos of number " << number << " is: " << pos << std::endl;
	}

	return 0;
}