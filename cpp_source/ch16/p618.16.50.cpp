#include <iostream>

template <typename T>
void f(T a){
    std::cout << "f(T a)" << std::endl;
}

template <typename T>
void f(const T* a) {
    std::cout << "f(const T* a)" << std::endl;
}

template <typename T>
void g(T a) {
    std::cout << "g(T a)" << std::endl;
} 

template <typename T>
void g(T* a) {
    std::cout << "g(T* a)" << std::endl;
}

int main() {
    int  i = 42, *p = &i;
    const  int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
    return 0;
}