#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    std::ifstream fin("./data/input/str");
    assert(fin.good());
    fin.tie(&std::cout);
    std::string str;
    StrBlob SBdemo;
    while (getline(fin, str)) {
        SBdemo.push_back(str);
    }
    auto SBptr = SBdemo.begin();
    while (!eq(SBptr,SBdemo.end())) {
        std::cout << SBptr.deref();
        SBptr.incr();
    }

    return 0;
}