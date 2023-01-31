/*
本例是我在阅读第七章时，突然想起这些宏操作没有完全理解，故亲手使用一下
*/
#include <iostream>
#define SW

int main()
{
    #ifndef SW
    std::cout << "yes" << std::endl;
    #endif
    return 0;
}