#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    Screen<5, 8> myScreen;
    std::cout << "Please Enter a string for screen: ";
    std::cin >> myScreen;
    std::cout << std::endl;
    std::cout << myScreen;
    std::cout << std::endl;
    myScreen.display(std::cout);
    std::cout << std::endl;
    
    return 0;
}