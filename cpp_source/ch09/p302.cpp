#include <vector>
#include <array>
#include <iostream>

int main() {
    std::vector<int> v1(10, 5);
    std::vector<int> v2(5);
    v1 = v2;
    std::vector<int>* pv1 = &v1;
    std::cout << *pv1->begin() << std::endl;
    std::cout << v1.size() << std::endl;
    v1 = {1,2,3,4,5,6};
    std::cout << v1.size() << std::endl;
    v1 = v2;
    v1.push_back(3);
    std::cout << *pv1->begin() << std::endl;
    std::cout << *(pv1->end() - 1) << std::endl;
    return 0;
}