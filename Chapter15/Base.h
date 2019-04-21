#pragma once
#ifndef _BASE_H_
#define _BASE_H_

class Base
{
public:
    virtual int fcn() {
        std::cout << "Base::fcn()" << std::endl;
        return 1;
    }
};

class D1:public Base
{
public:
    int fcn(/*int*/) {
        std::cout << "D1::fcn(int)" << std::endl;
        return 2;
    }
    virtual void f2() {
        std::cout << "D1::f2()" << std::endl;
    }
};

class D2 :public D1
{
public:
    int fcn(int) {
        std::cout << "D2::fcn(int)" << std::endl;
        return 3;
    }
    int fcn() {
        std::cout << "D2::fcn()" << std::endl;
        return 4;
    }
    void f2() {
        std::cout << "D2::f2()" << std::endl;
    }
};

#endif // !_BASE_H_
