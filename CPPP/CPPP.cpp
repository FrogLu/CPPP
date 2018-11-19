// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int& foo() {
    int b = 55;
    int& i = b;
    return i;
}
int foobar() {
    return 0;
}
int main() {
    vector<bool> bvec;
    vector<int> ivec;
    unsigned int *ui;
    int *p;
    unsigned int *up;
    cout << "size of vector<int>: " << sizeof(vector<int>) << endl;
    cout << "size of vector<bool>: " << sizeof(vector<bool>) << endl;
    cout << "sieze of int: " << sizeof(int) << endl;
    cout << "sieze of Uint: " << sizeof(unsigned int) << endl;
    cout << "sieze of int*: " << sizeof(int*) << endl;
    cout << "sieze of Uint*: " << sizeof(unsigned int*) << endl;
    cout << "sieze of Uint64: " << sizeof(unsigned _int64) << endl;
    cout << "sieze of bvec: " << sizeof(std::allocator<unsigned int>) << endl;
    int x[10]; int *ptr = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(ptr) / sizeof(*ptr) << endl;
    cout << endl;
    return 0;
}