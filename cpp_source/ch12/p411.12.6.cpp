#include <iostream>
#include <vector>
#include <memory>

// std::vector<int>* allocate_vector() {
//     return new std::vector<int>;
// }

// void destroy_vector(std::vector<int> *p) {
//     delete [] p;
// }

// void load_vector(std::vector<int> *p) {
//     int i = 0;
//     while (std::cin >> i) {
//         p->push_back(i);
//     }
// }

// void print_vector(std::vector<int> *p) {
//     for (auto i : *p) {
//         std::cout << i << " " ;
//     }
//     std::cout << std::endl;
// }

// 下面是使用智能指针的版本
std::shared_ptr<std::vector<int>> allocate_vector() {
    return std::make_shared<std::vector<int>> ();
} 

void load_vector(std::shared_ptr<std::vector<int>> p) {
    int i(0);
    while (std::cin >> i) {
        p->push_back(i);
    }
}

void print_vector(std::shared_ptr<std::vector<int>> p) {
    for (auto i : *p) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::shared_ptr<std::vector<int>> p = allocate_vector();
    load_vector(p);
    print_vector(p);
    // destroy_vector(p);
    return 0;
}

