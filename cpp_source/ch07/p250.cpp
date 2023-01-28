/*
p250 练习题7.3.3
*/
#include <iostream>

class Y;

class X{
    private:
        Y *ptr;
};

class Y{
    private:
        X x; 
};