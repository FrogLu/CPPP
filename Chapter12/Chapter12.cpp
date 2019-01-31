#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
	std::ifstream fin("./data/input/int");
	assert(fin.good());
	std::ofstream fout("./data/output/int");
	assert(fout.good());
	OutputFoo(fout,InputFoo(fin, Foo()));

	return 0;
}