#include <iostream>
#include <map>

int main() {
    std::map<int, int> mp;
    mp.insert({1,2});
    mp.insert({5,2});
    mp.insert({6,2});
    mp.insert({2,2});
    mp.insert({3,2});
    mp.insert({4,2});

    for (std::map<int, int>::const_iterator iter = mp.cbegin(); iter != mp.cend(); ++iter) {
        std::cout << "first: " << iter->first
            << " second: " << iter->second << std::endl;
    }

    std::map<int, int>::const_iterator iter = mp.lower_bound(10);
    std::cout << iter->first <<" " << iter->second << std::endl;
    // std::cout << mp.end()->first << " " << mp.end()->second << std::endl;

    return 0;
}