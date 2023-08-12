#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& print(std::ostream& os, const T &t) {
    os << t;
    return os;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args& ... rest) {
    os << t << ',';
    return print(os, rest...);
}

int main() {
    int i = 85;
    std::string s("jojlojjhgahhg");
    print(std::cout, i, s, 42);
    return 0;
}
