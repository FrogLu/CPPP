#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    Screen<5, 6> myScreen;
    myScreen.display(std::cout);
    myScreen.move(4, 0).set('#');

    Screen<5, 5> nextScreen('X');
    nextScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    nextScreen.display(std::cout);
    std::cout << std::endl;

    const Screen<5, 3> blank;
    myScreen.set('#').display(std::cout);   //  non-const version display
    std::cout << std::endl;
    blank.display(std::cout);   //  const version display
    std::cout << std::endl;

    myScreen.clear('Z').display(std::cout);
    std::cout << std::endl;
    myScreen.move(4, 4);
    myScreen.set('#');
    myScreen.display(std::cout);
    std::cout << std::endl;
    myScreen.clear('Z').display(std::cout);
    std::cout << std::endl;

    Screen<5, 6> temp = myScreen.move(4, 0);
    temp.set('#');
    myScreen.display(std::cout);
    std::cout << std::endl;
    
    return 0;
}