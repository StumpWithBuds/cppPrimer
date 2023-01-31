/*
在阅读P248时,突然想到一个问题：函数名相同，但返回类型不同的函数能否重载？
答案是下面的形式可以重载。主要是能区分形参，即形参的类型或/和形参的数量要不一样。
如果两个的fun函数的形参类型都改成一样的，就不行。
书上讲重载的部分有提到。
*/

#include <iostream>

double fun(double db){
    std::cout << "double fun" << std::endl;
    return db;
}

int fun(int it){
    std::cout << "int fun" << std::endl;
    return it;
}

int main()
{
    int it = 10;
    double db = 8.5;
    fun(it);
    fun(db);
    return 0;
}