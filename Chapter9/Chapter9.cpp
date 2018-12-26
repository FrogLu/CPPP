#include "pch.h"
#include "myfunction.h"
#include <iostream>
using namespace std;
int main()
{
	/*文件流输入初始化*/
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	std::forward_list<string> flststr;
	std::string str;
	std::string str1("xixi"), str2("FrogLu");
	while (fin >> str) {
		flststr.push_front(str);
	}
	/*原容器对象输出*/
	cout << "flststr(prev): ";
	for (auto &str : flststr) {
		cout << str << " ";
	}
	cout << endl;
	/*判断*/
	auto prev = flststr.before_begin(), curr = flststr.begin();
	flstInsertStr(flststr, str1, str2);
	/*输出*/
	cout << "flststr(curr): ";
	for (auto &str : flststr) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
