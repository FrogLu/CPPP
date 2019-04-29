#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"
#include "Basket.h"
#include "myfunction.h"
#include "StrBlob.h"
#include "TextQuery.h"
#include "Query.h"

int main() {
    // Input
    std::ifstream fin("./data/Input/paper");
    assert(fin);
    TextQuery file(fin);
    std::vector<std::array<std::string, 3>> h;

    while (true) {
        std::string sought1, sought2, sought3;
        if (!get_word(sought1)) {
            break;
        }
        if (sought1 != "h") {
            std::cout << "\n" << "enter second and third words: ";
            std::cin >> sought2 >> sought3;

            Query q = Query(sought1) & Query(sought2) 
                | Query(sought3);
            h.push_back({ sought1,sought2,sought3 });
            std::cout << "\nExecuting Query for: " << q << std::endl;
            const auto results = q.eval(file);
            //  Output
            std::cout << results;
        }
        else {
            std::cout << "\n" << "enter Query no.: ";
            std::size_t i;
            std::cin >> i;
            if (i<1 || i>h.size()) {
                std::cout << "\nBad Query no." << std::endl;
            }
            else {
                Query q = Query(h[i - 1][0]) & Query(h[i - 1][1])
                    | Query(h[i - 1][2]);
                std::cout << "\nExecuting Query for: " << q << std::endl;
                const auto results = q.eval(file);
                //  Output
                std::cout << results;
            }
        }
    }

    return 0;
}