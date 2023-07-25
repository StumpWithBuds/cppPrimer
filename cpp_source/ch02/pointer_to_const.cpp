/*
const double* 关键是看const double,意思是一个指向const double的指针，所以不能修改指针所指的内容。
而指针指向谁是可以改变的。
也可以指向一个不加const的变量。因为double b; const double a = b;。
*/

#include <iostream>

int main() {
    double a = 3.1415;
    const double* captr = &a;
    std::cout<< *captr << std::endl; //3.1415
    // *dptr = 3.04; // error: assignment of read-only location '* dptr'
    const double b = 1.234;
    const double *cbptr = &b;
    std::cout << *cbptr << std::endl;
    // double* bptr = &b; // error: invalid conversion from 'const double*' to 'double*'
    cbptr = &a;
    std::cout << *cbptr << std::endl;
    return 0;
}