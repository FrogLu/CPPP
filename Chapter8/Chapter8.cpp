// Chapter8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "myStream.h"
string infile = "input" ;
const string outfile =  "output" ;
int main()
{
	// istream
	//cout << "Please enter some integer, press Ctrl + Z to end." << endl;
	//myprint(cin);
	// fstream
	ifstream in(infile);
	ofstream out(outfile, std::ofstream::app);// 显式指定app模式，保留原文件内容
	//vector<string> vstr;
	//if (process(in, vstr)) {
	//	in.close();
	//	process(out, vstr);
	//	out.close();
	//}
	// stringstream
	string line, word;
	vector<PersonInfo> people;
	while (getline(in, line)) {
		PersonInfo info;
		std::istringstream record(line);
		//myprint(record);// 要使用该函数，需先对myprint进行修改
		if (out.is_open()) {
			out << line << endl;
		}
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	in.close();
	out.close();
	// Practice9.4
	vector<int> vint = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	const int val = 11;
	myfind(vint, val);
	//cout << "The result is:"
	//	<< *myfind(vint, val) << endl;
	return 0;
}