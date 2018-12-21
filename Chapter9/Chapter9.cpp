#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	list<string> slist1(1);
	slist1.assign(10, "Hiya!");

	vector<string> svec1(10,"hello");
	vector<string> svec2(24,"world");
	auto it1 = svec1.begin();
	auto it2 = svec2.begin();
	//cout << "The first element of svec1 is " << *svec1.begin() << endl;
	//cout << "The first element of svec2 is " << *svec2.begin() << endl;
	//swap(svec1, svec2);
	//cout << "The first element of svec1 is " << *svec1.begin() << endl;
	//cout << "The first element of svec2 is " << *svec2.begin() << endl;

	cout << "The first element of svec1 is " << *it1 << endl;
	cout << "The first element of svec2 is " << *it2 << endl;
	swap(svec1, svec2);
	cout << "The first element of svec1 is " << *it1 << endl;
	cout << "The first element of svec2 is " << *it2 << endl;

	char cp = 'a';
	char * a = &cp;
	list<const char *> lcp = { "hello","world","!" };
	vector<string> svec;
	svec.assign(lcp.cbegin(), lcp.cend());
	cout << svec.capacity() << " " << svec.size() << " "
		<< svec[0] << " " << svec[svec.size() - 1] << endl;
	return 0;
}
