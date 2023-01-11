#include <iostream>

int main(){
    // int i = -1, &r = 0; //不合法, r 必须引用一个对象
    int i = -1, &r = i;
    const int *ptr; //指向常量的指针可以不初始化，但是指向的地址是未知的
    // int *const cptr; //不合法,常量指针必须初始化
    std::cout << *ptr << std::endl;
    return 0;
}