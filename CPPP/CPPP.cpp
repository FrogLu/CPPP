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
constexpr int new_sz() {
    return 42;
}
constexpr int scale(int cnt) {
    return new_sz() * cnt;
}
int main(int argc,char **argv) {
    int i = 2;
    while (cin >> i) {
        assert(i > 0);
#ifndef NDEBUG
        if(i!=2)
        cerr << "Error: " << __FILE__
            << " : in function " << __func__
            << " at line " << __LINE__ << endl
            << " Complied on " << __DATE__
            << " at " << __TIME__ << endl
            << " Number read was \"" << i
            << "\": is not 2" << endl;
#endif
    }
    
    /*int a2[scale(i)];*/
    /*constexpr int s = scale(i);*/
    return 0;
}