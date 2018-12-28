#include "pch.h"
#include "myfunction.h"
using namespace std;
#define MPREFIX "Mr. "
#define FMPREFIX "Ms. "
#define MSUFFIX " Jr."
#define FMSUFFIX " III"

int main()
{
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	string num;
	vector<string> svec;
	vector<int> ivec;
	vector<double> dvec;
	int isum = 0;
	double dsum = 0;
	while(fin >> num) {
		svec.push_back(num);
	}
	for (auto &c : svec) {
		ivec.push_back(stoi(c));
		dvec.push_back(stod(c));
		isum += stoi(c);
		dsum += stod(c);
	}
	cout << "int sum: " << isum << endl;
	cout << "double sum: " << dsum << endl;
	return 0;
}
