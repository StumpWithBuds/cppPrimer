#include <iostream>

template <typename T1>
auto sum = [] (T1 &elem1, T1 &elem2) -> T1 {
    return elem1 + elem2;
};

int main() {
    int a = 4, b = 9;
    std::cout << sum<int>(a, b) << std::endl;
    return 0;
}