#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> v1{1,2,3,4,5,6};
    std::cout << v1.front() << " " << *v1.begin() << " " << v1.at(0) << std::endl;
    return 0;
}