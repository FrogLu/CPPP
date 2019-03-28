#include "pch.h"
#include "HasPtr.h"

void f1(HasPtr hp) {

}

void f2(HasPtr& hp) {

}

int main()
{
    std::cout << "Local variable: " << std::endl;
    HasPtr hp;
    std::cout << std::endl;

    std::cout << "Non-reference parameter: " << std::endl;
    f1(hp);
    std::cout << std::endl;

    std::cout << "Reference parameter: " << std::endl;
    f2(hp);
    std::cout << std::endl;

    std::cout << "Dynamic allocation: " << std::endl;
    HasPtr* php = new HasPtr;
    std::cout << std::endl;

    std::cout << "Add in container: " << std::endl;
    std::vector<HasPtr> vhp;
    vhp.push_back(hp);
    std::cout << std::endl;

    std::cout << "Release dynamic allocation object: " << std::endl;
    delete php;
    std::cout << std::endl;

    std::cout << "Indirect initialization and assignment: " << std::endl;
    HasPtr y = hp;
    y = hp;
    std::cout << std::endl;

    std::cout << "End of program: " << std::endl;

    return 0;
}
