#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin_map("./data/Input/map");
	std::ifstream fin_map_test("./data/Input/map_test");
	assert(fin_map.good());
	assert(fin_map_test.good());
	fin_map_test.tie(&cout);
	word_transform(fin_map, fin_map_test);
	
	return 0;
}
