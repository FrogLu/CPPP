#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    Blob<int> ia;
    Blob<int> ia2 = { 0,1,2,3,4 };
    Blob<std::string> strb = { "hello","world","FrogLu" };
    print(ia2.begin(),ia2.end());
    std::cout << std::endl;
    print(strb.begin(), strb.end());
    
    return 0;
}