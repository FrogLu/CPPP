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
	std::ostream_iterator<int> ositer(cout, " ");
	std::list<int> ilst;
	std::vector<int> ivec(isiter,eof);
	std::cout << "vector member: " << std::endl;
	for (auto val : ivec) {
		ositer = val;
	}
	std::cout << std::endl;
	ilst.assign(ivec.rend() - 7, ivec.rend() - 2);	// 顺序容器的左闭右开区间假定
													// 所以后者是-2不是-3.
	std::cout << "list member: " << std::endl;
	for (auto val : ilst) {
		ositer=val;
	}

	return 0;
}