#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print(T container) {
    typedef typename T::iterator iterator;
    for (iterator iter = container.begin(); iter != container.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}

int main() {
    std::list<double> li{1.2,1.3,1.4,2.5,3.55,9.8};
    print(li);
    std::vector<float> vec{1.2,45.6,5.56};
    print(vec);
    return 0;
}