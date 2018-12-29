#include "pch.h"
#include "myfunction.h"
using namespace std;

int main()
{
	//std::ifstream finnum("inputnum.txt");
	//finnum.tie(&cout);
	//int val;
	//const int target = 4519;
	//vector<double> dvec;
	//while (finnum >> val) {
	//	dvec.push_back(val);
	//}
	//fill_n(dvec.begin(), dvec.size(), 0);

	std::ifstream finstr("inputstr.txt");
	finstr.tie(&cout);
	string str;
	vector<string> svec;
	while (finstr >> str) {
		svec.push_back(str);
	}
	elimDups(svec);

	return 0;
}
