#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"

int main() {
    StrVec svec({ "hello","world","Froglu" });
    const StrVec cvec = svec;
    std::cout << "svec: " << svec[0] << std::endl;
    svec[0] = "zero";
    std::cout << "svec: " << svec[0] << std::endl;
    std::cout << "cvec: " << cvec[0] << std::endl;

    return 0;
}