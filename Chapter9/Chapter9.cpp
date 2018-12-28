#include "pch.h"
#include "myfunction.h"
using namespace std;

int main()
{
	std::ifstream fin("input1.txt");
	fin.tie(&cout);

	string s = "tho thru tho!";
	cout << replace_string_KMP(s, "thru", "xixi") << endl;
	cout << s << endl;

	return 0;
}
