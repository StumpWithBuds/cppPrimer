#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T1, typename T2>
int func(T1 vec, T2 target){  
    return count(vec.cbegin(), vec.cend(), target);
}

int main() {
    std::vector<int> vec{1,2,3,3,3,3,3,3,3,4};
    std::cout << func(vec, 3) << std::endl;
    std::list<std::string> li{"123","123","123","123456"};
    std::cout << func(li, "123") << std::endl;
    return 0;
}