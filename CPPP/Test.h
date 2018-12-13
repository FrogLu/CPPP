#pragma once
#ifndef _TEST_H_
#define _TEST_H_
#include <string>
/****这是为了说明：可以定义一个指针指向一个不完全类型的类(仅有声明)*****/
/*但不能在类的定义中使用一个一个不完全类型的类，也就是说要先指针，后类型*/
class X;
class Y {
	X* ymem;
};
class X {
	Y xmem;
};

class NoDefault {
public:

	NoDefault(const std::string& = " ") {};
};
struct A {
	NoDefault my_mem;
}; 
A a;
struct B {
	//B() {}
	NoDefault b_member;
};
#endif