/*
float* const captr中，const是限定的captr,表明captr是不能更改的（const是限制const后面最近的），
但是captr所指向的内容是可以修改的，因为captr所指向的内容是float类型的。*/
#include <iostream>

int main() {
    float a = 3.1415;
    float* const captr = &a;
    std::cout << *captr << std::endl;
    *captr = 0.1234;
    std::cout << *captr << std::endl;
    float b = 5.123;
    // captr = &b; // error: assignment of read-only variable 'captr'
    return 0;
}