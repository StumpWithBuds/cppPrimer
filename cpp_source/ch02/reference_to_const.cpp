#include <iostream>

int main() {
    int a = 1;
    const int &ref_a = a;
    // ref_a = 8; //buggy
    std::cout << ref_a << std::endl;
    const int b = 2;
    // int &ref_b = b;
    return 0;
}