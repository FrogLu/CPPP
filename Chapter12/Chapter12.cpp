#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    std::allocator<std::string> alloc;
    auto const sp = alloc.allocate(10);
    std::string str;
    std::string* sq = sp;
    while (std::cin >> str && sq != sp + 10) {
        alloc.construct(++sq, str);
    }
    const size_t size = sq - sp;

    for (size_t i = 0; i < size; ++i) {
        std::cout << sp[i] << " " << std::endl;
    }
    
    while (sq != sp) {
        alloc.destroy(--sq);
    }
    alloc.deallocate(sp, 10);   // Even not 10, complier won't pop error.  

    return 0;
}