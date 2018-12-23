#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	vector<string> svec = { "quasi","simba","frollo","scar" };
	list<string> slist;

	cout << *slist.insert(slist.begin(), { "xixi" ,"Hello!" ,"world!"}) 
		<< endl;
	cout << *slist.insert(slist.end(), svec.begin(), svec.end()) << endl;
	cout << *slist.insert(slist.end(), { "xixi" ,"Hello!" ,"world!" }) 
		<< endl;

	return 0;
}
