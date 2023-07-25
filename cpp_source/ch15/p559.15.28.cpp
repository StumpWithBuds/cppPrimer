#include "./ex_15_26/quote.h"
#include "./ex_15_26/disc_quote.h"
#include "./ex_15_26/bulk_quote.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

int main() {
    std::vector<Quote> Quo_vec;
    for (int i = 0; i < 10; ++i) {
        Quo_vec.push_back(Bulk_quote("123", 3.2, 2, 2.2));
    }
    double total;
    for (int i = 0; i <Quo_vec.size(); ++i) {
        total += Quo_vec[i].net_price(20);
    }
    std::cout << total << std::endl;

    std::vector<std::shared_ptr<Quote>> QuoPtr_vec;
    for (int i = 0; i < 10; ++i){
        QuoPtr_vec.push_back(std::make_shared<Bulk_quote>("123", 3.2, 2, 2.2));
    }
    double total2;
    for (int i = 0; i < QuoPtr_vec.size(); ++i) {
        total2 += QuoPtr_vec[i]->net_price(20);
    }
    std::cout << total2 << std::endl;

    return 0;
}