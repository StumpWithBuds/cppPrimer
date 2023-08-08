#include <iostream>
#include <vector>

template <typename T>
void print(T container) {
    typedef typename T::size_type size_type;
    for (auto item : container) {
        std::cout << item << std::endl;
    }
    for (size_type i = 0; i < container.size(); ++i) {
        std::cout << container[i] << std::endl;
    }
}

int main() {
    std::vector<double> vec{1.2,2.3,3.4,4.56};
    print(vec);
    return 0;
}