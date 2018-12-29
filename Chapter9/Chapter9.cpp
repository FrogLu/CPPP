#include "pch.h"
#include "myfunction.h"
using namespace std;

int main()
{
	std::ifstream fin("inputnum.txt");
	fin.tie(&cout);
	int val;
	const int target = 4519;
	vector<int> ivec;
	while (fin >> val) {
		ivec.push_back(val);
	}
	cout << "The count of " << target << " : ";
	cout << count(ivec.begin(), ivec.end(), target) << endl;
	return 0;
}
