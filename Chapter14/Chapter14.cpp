#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"
#include "myfunction.h"

int main() {
    std::ifstream fint("./data/Input/int");
    std::ifstream fstr("./data/Input/paper");
    assert(fint.good());
    assert(fstr.good());
    fint.tie(&std::cout);
    fstr.tie(&std::cout);
    std::istream_iterator<std::size_t> IsStIter(fint), StEeof;
    std::istream_iterator<std::string> IsStrIter(fstr), StrEof;
    std::vector<std::size_t> stvec(IsStIter, StEeof);
    std::vector<std::string> svec(IsStrIter, StrEof);
    //  Practice14.42
    auto a = std::count_if(stvec.cbegin(), stvec.cend(), 
        std::bind(std::greater<std::size_t>(), std::placeholders::_1,1024));
    auto b = std::find_if(svec.cbegin(), svec.cend(),
        std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, std::string("pooh")));
    auto c = std::transform(stvec.begin(), stvec.end(), stvec.begin(),
        std::bind(std::multiplies<std::size_t>(), std::placeholders::_1, 2));

    return 0;
}