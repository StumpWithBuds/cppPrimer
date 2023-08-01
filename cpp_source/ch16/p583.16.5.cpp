#include <iostream>
#include <array>

template <typename T>
void print(const T &arr) {
    for (auto item : arr){
        std::cout << item << std::endl;;
    }
}


int main() {
    std::array<double, 10> arr {1.2,3.4,5.6,7.8};
    return 0;
}