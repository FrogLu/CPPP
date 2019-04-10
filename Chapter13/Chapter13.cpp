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
    char ch[] = { 'h','e','l','l','o','\0' };
    String mystr(ch);
    std::vector<String> Svec;
    const std::size_t end = 10;
    for (std::size_t count = 0; count != end; ++count) {
        std::cout << "loop " << count << " : " << std::endl;
        Svec.push_back(mystr);
    }


    return 0;
}
