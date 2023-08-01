#include <iostream>
#include <vector>
#include <string>
#include <cstring>

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
} 

int main() {
    // std::string a = "hi", b = "mom";
    // char* p1 = "hi", *p2 = "mom";
    char p1[3] = "hi", p2[4] = "mom";
    // int result = compare("hi", "mom");
    int result = compare(p1, p2);
    std::cout << result << std::endl;
    return 0;
}