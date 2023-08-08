#include <iostream>

template <typename T>
int func(T a) {
    std::cout << a << std::endl;
    ++a;
    return a;
}

int main() {
    const int a = 3;
    const int b = func(a); //这里模板参数T是int
    std::cout << b << std::endl;
    return 0;
}