#include "pch.h"
#include "myfunction.h"
using namespace std;

int main()
{
	std::ifstream finnum("inputnum.txt");
	finnum.tie(&cout);
	int val;
	const int target = 4519;
	vector<int> ivec;
	while (finnum >> val) {
		ivec.push_back(val);
	}
	auto numsum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << "The sum of nums: " << numsum << endl;

	//std::ifstream finstr("inputstr.txt");
	//finstr.tie(&cout);
	//string str;
	//vector<string> svec;
	//while (finstr >> str) {
	//	svec.push_back(str);
	//}
	//string sum = accumulate(svec.cbegin(), svec.cend(), string(""));

	return 0;
}
