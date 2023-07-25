#include <iostream>

std::istream& func(std::istream& is) {
    std::string str;
    while(is >> str) {
        std::cout << str << std::endl;
    }
    is.clear();
    return is;
}

int main() {
    std::istream& is = func(std::cin);
    return 0;
}
