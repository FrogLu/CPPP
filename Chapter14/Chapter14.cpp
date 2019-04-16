#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"
#include "myfunction.h"

int main() {
    std::ifstream fint("./data/Input/int");
    std::ifstream fstr("./data/Input/str");
    assert(fint.good());
    assert(fstr.good());
    fint.tie(&std::cout);
    fstr.tie(&std::cout);
    std::istream_iterator<std::size_t> IsStIter(fint), StEeof;
    std::istream_iterator<std::string> IsStrIter(fstr), StrEof;
    std::vector<std::size_t> stvec(IsStIter, StEeof);
    std::vector<std::string> svec(IsStrIter, StrEof);
    //  Practice14.42
    //std::sort(stvec.cbegin(), stvec.cend(), std::greater<std::size_t>());
    auto a = std::count_if(stvec.cbegin(), stvec.cend(), 
        std::greater<std::size_t>()/*greater() have two arguments, so it doesn't work.*/);

    return 0;
}