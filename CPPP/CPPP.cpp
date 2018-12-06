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
int foo(int, int) {
    return 0;
}
int myplus(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int mult(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    return a / b;
}
int main(int argc,char **argv) {
    vector<decltype(foo)*> funcVec = {foo,myplus,subtract,mult,divide};
    for (auto c : funcVec) {
        cout << c << endl;
    }
    return 0;
}