#include "pch.h"
#include "TextQuery.h"

std::ostream& print(std::ostream& out, const TextQuery::MAP::iterator& iter)
{
    for (auto& c : iter->second) {
        out << c << " ";
    }
    return out;
}
void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string str;
        if (!(std::cin >> str) || str == "q") {
            break;
        }
        print(std::cout, tq.query(str)) << std::endl;
    }
}


