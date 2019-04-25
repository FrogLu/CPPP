#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    std::vector<Quote> basket;
    basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));
    basket.push_back(Bulk_quote("1-201-54848-8", 40, 10, .25));
    double count = 0.0;
    for (auto& b : basket) {
        count += b.net_price(15);
    }
    std::cout << "Books' net_price total is : " << count << std::endl;  //  count is 1350

    return 0;
}