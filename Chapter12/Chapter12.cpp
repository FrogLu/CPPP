#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"
#include "TextQuery.h"



int main()
{
    std::ifstream fin("./data/input/paper");
    assert(fin.good());
    myrunQueries(fin);

    return 0;
}