#include <iostream>
#include <vector>

template <typename T>
size_t countNum(std::vector<T> vec, T target) {
    size_t count = 0;
    for (typename std::vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
        if(*iter == target) 
            ++count;
    }
    return count;
}

template <>
size_t countNum(std::vector<const char*> vec, const char* target) {
    size_t count = 0;
    for (auto item : vec) {
        if (item == target) {
            ++count;
        }
    }
    std::cout << "use special" << std::endl;
    return count;
}

int main() {
    std::vector<int> vec1{1,2,3,4,4,6};
    std::vector<double> vec2{2.2, 3.1,3.5,3.5,6.9};
    std::vector<const char*> vec3{"123","123","jkl","54opj"};
    size_t count1 = countNum(vec1, 4);
    size_t count2 = countNum(vec2, 3.9);
    size_t count3 = countNum(vec3, "jkl");
    std::cout << count1 << std::endl;
    std::cout << count2 << std::endl;
    std::cout << count3 << std::endl;
    return 0;
}