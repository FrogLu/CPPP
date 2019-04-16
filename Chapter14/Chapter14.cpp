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
    //std::size_t count = 0;
    const std::size_t begin = 1, end = 10;
    //for (std::string::size_type threshold = begin; threshold != end; ++threshold) {
    //    CheckSize cs(threshold);
    //    count += std::count_if(svec.cbegin(), svec.cend(), cs);
    //    countVec.push_back(count);
    //}
    //std::cout << "count of word's length " << begin << "-" << end - 1 << " in paper: ";
    //std::cout << count << std::endl;
    //std::cout << "length more than: " << end << " in paper: " << svec.size() - count << std::endl;
    StrLenBetween slenBetween(1, 9);
    StrNotShorterThan sNotShorterThan(10);
    std::cout << "count of word's length " << begin << "-" << end - 1 << " in paper: ";
    std::cout << std::count_if(svec.cbegin(),svec.cend(),slenBetween) << std::endl;
    std::cout << "length more than: " << end << " in paper: ";
    std::cout<< std::count_if(svec.cbegin(),svec.cend(),sNotShorterThan) << std::endl;

    return 0;
}