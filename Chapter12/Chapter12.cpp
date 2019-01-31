#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
	std::ifstream fin("./data/input/int");
	assert(fin.good());
	std::ofstream fout("./data/output/int");
	assert(fout.good());
	auto* pivec = Foo();
	InputFoo(fin, pivec);
	OutputFoo(fout, pivec);
	delete pivec;
	pivec = nullptr;

	return 0;
}