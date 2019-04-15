#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"

int main() {
    std::ifstream fin("./data/Input/paper");
    assert(fin.good());
    fin.tie(&std::cout);
    std::istream_iterator<std::string> isiter(fin), eof;
    std::vector<std::string> svec(isiter,eof);
    std::vector<std::size_t> countVec;
    for (auto& s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    for (std::string::size_type threshold = 1; threshold != 11; ++threshold) {
        CheckSize cs(threshold);
        auto count = std::count_if(svec.cbegin(), svec.cend(), cs);
        std::cout << "count of word's length " << threshold << " in paper: " << count << std::endl;
        countVec.push_back(count);
    }
    

    return 0;
}