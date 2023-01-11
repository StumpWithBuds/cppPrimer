#include <iostream>

int main()
{
    int ival = 1024;
    int &refval = ival;
    refval = 2048;
    std::cout << ival <<std::endl;
    int i = 1.01;
    std::cout << i << std::endl;
    return 0;
}