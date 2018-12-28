#include "pch.h"
#include "myfunction.h"
using namespace std;
#define MPREFIX "Mr. "
#define FMPREFIX "Ms. "
#define MSUFFIX " Jr."
#define FMSUFFIX " III"

int main()
{
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	int i = 0, j;
	//cout << "i: " << i << "j: " << j << endl;
	j = ++i;
	cout << "i: " << i << "j: " << j << endl;
	j = i++;
	cout << "i: " << i << "j: " << j << endl;
	/* 参考答案更好 */
	bool bpre=false, bcurr=false;
	string pre,curr;
	string maxword;
	while (bpre == false && fin >> pre) {
		bpre = findword(pre);
	}
	if (bpre == true) {
		maxword = pre;
	}
	while (fin >> curr) {
		bcurr = findword(curr);
		if (bcurr == true) {
			if (curr.size() >= pre.size()) {
				maxword = curr;
				pre = curr;
			}
			else {
				maxword = pre;
			}
		}
	}
	if (maxword == "") {
		cout << "Can't find the word!" << endl;
	}
	else {
		cout << "The max word is: " << maxword << endl;
	}
	return 0;
}
