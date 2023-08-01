#include <iostream>
#include <vector>
#include <string>

template <typename T>
int compare(const T& t1, const T& t2) {
    if (t1 > t2) return 1;
    else if (t1 < t2) return -1;
    return 0;
}



int main() {
    int t1 = 1, t2 = 0;
    int result = compare(t1, t2);
    std::cout << result << std::endl;
    return 0;
}