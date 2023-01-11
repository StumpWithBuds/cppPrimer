#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl; //结果-84
    std::cout << u + i << std::endl; //结果4294967264，相加之前整数-42转换成无符号数。CSAPP里有出现这个问题的答案。
    return 0;
}