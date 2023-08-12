#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    int num = accumulate(vec.begin(), vec.end(), 0);
    std::cout << num << std::endl;
    return 0;
}