#include "pch.h"
#include "myfunction.h"
using namespace std;
#define MAX_LIMIT 1000
#define MYSTRING "hello"
int main()
{
	vector<string> svec;
	svec.reserve(1024);
	string word;
	int val = 0;
	while ( val!=MAX_LIMIT) {
		svec.push_back(MYSTRING);
		++val;
	}
	cout << "size: " << svec.size()
		<< " capacity: " << svec.capacity() << endl;
	svec.resize(svec.size() + svec.size() / 2);
	cout << "size: " << svec.size()
		<< " capacity: " << svec.capacity() << endl;
	return 0;
}
