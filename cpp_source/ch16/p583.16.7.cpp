#include <iostream>
#include <vector>
#include <array>

template <typename T, unsigned N>
unsigned size(const T (&arr)[N]){
    return N;
}

template <typename T, unsigned N>
unsigned size(const std::array<T, N> &arr) {
    return N;
}


int main() {
    int length = 0;
    int length2 = 0;
    std::array<double, 10> arr = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    double array[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    length = size(array);
    length2 = size<double, 10>(arr);
    std::cout << length << std::endl;
    std::cout << length2 << std::endl;
    return 0;
}