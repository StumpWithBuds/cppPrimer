#include <iostream>
#include <string>

int func(const int input) {
    int x = 85;
    auto sum = [x] (const int a) -> int {
        return x + a;
    };
     
    return sum(input);
}

int main() {
    int a = 10;
    int result = func(a);
    std::cout << result << std::endl;
    return 0;
}