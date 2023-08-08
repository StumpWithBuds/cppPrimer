#include <iostream>
#include <string>
#include <sstream>

template <typename T>
std::string debug_rep(const T& t) {
    std::ostringstream ret;
    ret << t;
    std::cout << "debug_rep(const T& t)" << std::endl;
    return ret.str();
}

template <typename T>
std::string debug_rep(T* p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        std::cout << "debug_rep(T* p)" << std::endl;
        ret << " " << debug_rep(*p);
    }
    else 
        ret << " null pointer" << std::endl;
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

int main() {
    std::string s("hi");
    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep(&s) << std::endl;
    return 0; 
}