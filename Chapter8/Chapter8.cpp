// Chapter8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "myStream.h"
string infile = "input" ;
const string outfile =  "output" ;
int main()
{
	//cout << "Please enter some integer, press Ctrl + Z to end." << endl;
	//myprint(cin);
	
	ifstream in(infile);
	ofstream out(outfile, std::ofstream::app);// ��ʽָ��appģʽ������ԭ�ļ�����
	vector<string> vstr;
	if (process(in, vstr)) {
		return process(out, vstr);
	}
	return 0;
}