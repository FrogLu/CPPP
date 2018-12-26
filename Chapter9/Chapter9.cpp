#include "pch.h"
#include <iostream>
using namespace std;
#define some_val 3
int main()
{
	/*文件流输入*/
	std::ifstream fin("input2.txt");
	fin.tie(&cout);
	vector<int> ivec;
	list<int> ilist;
	forward_list<int> flst;
	int val;
	while (fin >> val) {
		ivec.push_back(val);
	}
	ilist.assign(ivec.begin(),ivec.end());
	flst.assign(ivec.begin(), ivec.end());
	/*赋值结束*/
	auto prev = flst.before_begin(), curr = flst.begin();
	while (curr != flst.end()) {
		if ((*curr) & 1) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}
	/*输出*/
	cout << "flst: ";
	for (auto &val : flst) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
