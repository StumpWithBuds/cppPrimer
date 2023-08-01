#include <iostream>
#include <vector>
#include <list>

int main() {
    // std::vector<double> v1(10, 3.2);
    // std::list<int> l1(v1.begin(), v1.end());
    // std::cout << *l1.begin() << std::endl;

    std::list<int> l2(10,3);
    std::vector<double> v2(l2.begin(), l2.end());
    std::cout << *v2.begin() << std::endl;
    return 0;
}