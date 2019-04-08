#pragma once
#ifndef _NUMBERED_H_
#define _NUMBERED_H_

//class numbered;
//void f(numbered s);
class numbered
{

    friend void f(const numbered& s);
public:
    numbered();
    // 13.15
    numbered(const numbered& num);
    numbered operator=(const numbered& rhs);
    ~numbered();
private:
    int mysn;
    static int count;

};

//int numbered::count = 0;
// 13.16
inline void f(const numbered& s) {
    std::cout << s.mysn << std::endl;
}

#endif // !_NUMBERED_H_