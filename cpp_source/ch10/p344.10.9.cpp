#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void print(std::vector<std::string> vec) {
    for (std::string elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> vec{"123", "sfs", "123", "dssfs", "123"};
    elimDups(vec);
    print(vec);
    return 0;
}