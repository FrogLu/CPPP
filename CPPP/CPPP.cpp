// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PartA.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
//#define NDEBUG  //用于DEBUG
using namespace std;
void f() {
    cout << "This is no argument" << endl;
};
void f(int) {
    cout << "This is one int argument" << endl;
};
void f(int, int) {
    cout << "This is two int argument" << endl;
};
void f(double, double = 3.14) {
    cout << "This is two double argument" << endl;
};
int main(int argc,char **argv) {
    f(2.56,3.14);
    return 0;
}