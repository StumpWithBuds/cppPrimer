#include <iostream>
#include <list>
#include <string>

std::istream& inList(std::istream& is, std::list<std::string>& li) {
    std::string s;
    while (is >> s) {
        li.push_back(s);
    }
    return is;
}

void print(std::list<std::string> li) {
    for (std::list<std::string>::const_iterator iter = li.cbegin(); iter != li.cend(); iter++) {
        std::cout << *iter << std::endl;
    }
}

int main() {
    std::list<std::string> li;
    inList(std::cin, li);
    print(li);
    return 0;
}