#include "pch.h"
#include "Foo.h"



Foo::Foo()
{
}

Foo Foo::sorted() &&
{
    std::cout << "Foo::sorted() && called" << std::endl;
    std::sort(data.begin(), data.end());

    return *this;
}

Foo Foo::sorted() const &
{
    std::cout << "Foo::sorted() const & called" << std::endl;
    //Foo ret(*this);

    //return ret.sorted();
    return Foo(*this).sorted();
}


Foo::~Foo()
{
}
