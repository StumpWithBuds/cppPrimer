#include <iostream>
#include <utility>

void f(int, int &);
void g(int, int &);
void g(int &, int&&);
void g(int &&, const int &);

template <typename F, typename T1, typename T2>
void filp1(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2) {
    std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int i, int &j) {
    std::cout << i << " " << j << std::endl;
}

void g(int &i, int &&j) {
    std::cout << i << " " << j << std::endl;
}

void g(int &&i, const int &j) {
    std::cout << i << " " << j << std::endl;
}

int main() {
    int i = 2;
    filp1(f, i, 2);
    filp1<void (int, int&)>(g, i, 5);
    filp1<void (int&, int&&)>(g, 3, i);
    return 0;
}