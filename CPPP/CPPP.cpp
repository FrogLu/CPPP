// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PartA.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "Sales_data.h"
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
    const Sales_data test;
    test.isbn();
    return 0;
}