#include <iostream>
#include <string>
#include <vector>

struct X{
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
    X& operator=(const X&) {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() {std::cout << "~X()" << std::endl;}
};

void f(const X &rx, X x)
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); //这里把rx传入push_back()也调用了拷贝构造函数
    vec.push_back(x); //这里把x传入push_back()也调用了拷贝构造函数
}

int main() {
    X* xp = new X();
    f(*xp, *xp);
    delete xp;
    return 0;
}
