#include <iostream>
#include <string>
#include <deque>
#include <vector>

std::istream& inDeque(std::istream& is, std::deque<std::string>& deq) {
    std::string s;
    while (is >> s) {
        deq.push_back(s);
    }
    return is;
} 

void print(std::deque<std::string>& deq) {
    for (std::deque<std::string>::iterator iter = deq.begin(); iter != deq.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main () {
    std::deque<std::string> deq;
    inDeque(std::cin, deq);
    print(deq);
    return 0;
}