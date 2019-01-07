#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

int main()
{
	const int remainval = 11; // change the val to get a Pseudo random number.
	std::ofstream fout("./data/InputInt");
	assert(fout.good());
	int count = 20;
	while (--count) {
		fout << rand() % remainval << " ";
	}
	fout.close();
	/* fin starts */
	std::ifstream fin("./data/InputInt");
	assert(fin.good());
	fin.tie(&cout);
	int val;
	std::vector<int> ivec;
	while (fin>>val) {
		ivec.push_back(val);
	}
	for (auto i : ivec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	/* fin done */
	const string cstr = "hello";
	auto myfunc = bind(check_size, "hello",_1);
	for (auto i : ivec) {
		if (!myfunc(i)) {
			cout << "The first integer which is greater than " << cstr
				<< "'s size is: " << i << endl;
			break;
		}
	}


	return 0;
}