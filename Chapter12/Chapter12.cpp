#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    std::unique_ptr<double> p1;
    std::unique_ptr<int> p2(new int(42));
    std::unique_ptr<std::string> p3(new std::string("Stegosaurus"));
    std::unique_ptr<std::string> p4(p3.release());
    std::unique_ptr<std::string> p5(new std::string("Trex"));
    p4.reset(p5.release());

    return 0;
}