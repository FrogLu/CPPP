#pragma once
#ifndef _TEST_H_
#define _TEST_H_
#include <string>
/****����Ϊ��˵�������Զ���һ��ָ��ָ��һ������ȫ���͵���(��������)*****/
/*����������Ķ�����ʹ��һ��һ������ȫ���͵��࣬Ҳ����˵Ҫ��ָ�룬������*/
class X;
class Y {
	X* ymem;
};
class X {
	Y xmem;
};

class NoDefault {
public:
	NoDefault(int val) {};
	NoDefault(const std::string&) {};
};
struct A {
	NoDefault my_mem;
}; 
//A a;
struct B {
	//B() {}
	NoDefault b_member;
};
// Practice7.43
struct C {
	C() :NDc(10) {}
public:
	NoDefault NDc;
};
#endif