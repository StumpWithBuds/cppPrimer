#include <iostream>
#include <memory>
#include <cstring>

int main() {
    // std::string str;
    // std::cin >> str;
    // int len = str.size();
    // char* r(new char[len + 1]);
    // strcpy(r, str.c_str());
    // std::cout << r << std::endl;
    // return 0;

    std::string str1("");
    std::cin >> str1;
    int len = str1.size();
    char* r(new char[len + 1]);
    strcpy(r, str1.c_str());
    std::cout << r << std::endl;
    return 0;
}