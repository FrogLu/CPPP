#include "pch.h"
#include "myfunction.h"
using namespace std;
#define MPREFIX "Mr. "
#define FMPREFIX "Ms. "
#define MSUFFIX " Jr."
#define MSUFFIX " III"

int main()
{
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	string str;
	while (fin >> str) {
		/* find numbers */
		auto vposnum=findnum(str);
		if (!vposnum.empty()) {
			cout << "The position of numbers are: ";
			for (auto &pos : vposnum) {
				cout << pos << " ";
			}
			cout << endl;
		}
		else {
			cout << "Can't find any numbers in the string!" << endl;
		}
		/* find letters */
		auto vposletter = findletter(str);
		if (!vposletter.empty()) {
			cout << "The position of letters are: ";
			for (auto &pos : vposletter) {
				cout << pos << " ";
			}
			cout << endl;
		}
		else {
			cout << "Can't find any letters in the string!" << endl;
		}
	}

	return 0;
}
