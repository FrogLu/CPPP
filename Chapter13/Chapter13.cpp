#include "pch.h"
#include "HasPtr.h"
#include "numbered.h"
#include "NoDtor.h" //  a class which deleted its destructor
#include "test.h"   //  a class just for testing what I meet but the book doesn't told me.
#include "Employee.h"
#include "StrBlob.h"
#include "Message.h"
#include "Folder.h"
#include "myfunction.h"
#include "StrVec.h"
#include "TextQuery.h"
#include "String.h"

int main()
{
    String s1("One"), s2("Two");
    std::vector<String> vs;
    vs.push_back(s1);
    std::cout << std::endl;
    vs.push_back(std::move(s2));
    std::cout << std::endl;
    vs.push_back(String("Three"));
    std::cout << std::endl;
    vs.push_back("Four");
    std::cout << std::endl;
    std::for_each(vs.begin(), vs.end(), [](const String & s) {std::cout << s << " "; });
    std::cout << std::endl;

    return 0;
}
