#pragma once
#ifndef _TEST_H_
#define _TEST_H_
class Y;
class X {
	Y * X;
};
class Y {
	X Y;
};
typedef string Type;
Type initVal();
class Exercise {
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal() { return 1.0; };
private:
	int val;
};
Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}
#endif