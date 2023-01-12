#include <iostream>

typedef double wages;
typedef wages base, *p;
typedef int* intptr;
using F = float;

int main(){
    wages d = 3.14;
    p dptr = &d;
    std::cout << "d: " << d << "    " << "*dptr: " << *dptr << std::endl;
    int i = 8;
    intptr iptr = &i;
    std::cout << *iptr <<std::endl;
    F f = 8.5;
    std::cout << f << std::endl;
    return 0; 
}