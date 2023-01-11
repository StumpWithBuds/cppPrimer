#include <iostream>

int main(){
    const double pi = 3.14;
    const double *ptr = &pi;
    std::cout << *ptr <<std::endl;

    double dval = 6.28;
    const double *cptr = nullptr;
    cptr = &dval;
    std::cout << *cptr << std::endl;
    return 0;
}