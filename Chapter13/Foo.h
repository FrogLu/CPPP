#pragma once
#ifndef _FOO_H_
#define _FOO_H_

class Foo
{
public:
    Foo();
    Foo sorted() &&;
    Foo sorted() const &;
    ~Foo();
private:
    std::vector<int> data;
};

#endif // !_FOO_H_


