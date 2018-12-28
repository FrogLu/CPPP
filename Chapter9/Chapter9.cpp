#include "pch.h"
#include "myfunction.h"
using namespace std;
#define MPREFIX "Mr. "
#define FMPREFIX "Ms. "
#define MSUFFIX " Jr."
#define MSUFFIX " III"

int main()
{
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	string name;
	while (fin >> name) {
		cout << fullname(name,MPREFIX,MSUFFIX) << endl;
	}

	return 0;
}
