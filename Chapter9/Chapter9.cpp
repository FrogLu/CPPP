#include "pch.h"
#include "myfunction.h"
using namespace std;

int main()
{
	std::ifstream fin("inputnum.txt");
	fin.tie(&cout);
	int val;
	const int target = 4519;
	list<int> ilst;
	while (fin >> val) {
		ilst.push_back(val);
	}
	cout << "The count of " << target << " : ";
	cout << count(ilst.begin(), ilst.end(), target) << endl;
	return 0;
}
