#include "pch.h"
#include "myfunction.h"
#include <iostream>
using namespace std;
int main()
{
	/*�ļ��������ʼ��*/
	std::ifstream fin("input1.txt");
	fin.tie(&cout);
	std::forward_list<string> flststr;
	std::string str;
	std::string str1("xixi"), str2("FrogLu");
	while (fin >> str) {
		flststr.push_front(str);
	}
	/*ԭ�����������*/
	cout << "flststr(prev): ";
	for (auto &str : flststr) {
		cout << str << " ";
	}
	cout << endl;
	/*�ж�*/
	auto prev = flststr.before_begin(), curr = flststr.begin();
	flstInsertStr(flststr, str1, str2);
	/*���*/
	cout << "flststr(curr): ";
	for (auto &str : flststr) {
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
