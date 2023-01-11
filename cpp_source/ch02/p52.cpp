#include <iostream>

int main()
{
    int i = 42;
    int *p = nullptr;
    int *&r = p;
    r = &i;
    *r = 85;
    std::cout << i <<std::endl;
    return 0;
    
}