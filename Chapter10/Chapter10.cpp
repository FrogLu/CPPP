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
	std::vector<int> ivec(isiter, eof);
	std::cout << "Ascending: " << std::endl;
	for (auto iter = ivec.cbegin(); iter != ivec.cend(); iter++)
	{
		cout << *iter << " ";
	}
	std::cout<<std::endl;
	std::cout << "Descending: " << std::endl;
	auto riter = ivec.cend();
	while (--riter != ivec.cbegin())
	{
		std::cout << *riter << " ";
	}
	std::cout << *riter << std::endl;

	return 0;
}