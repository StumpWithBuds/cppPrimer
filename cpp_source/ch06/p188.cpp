/*
6.2.1节练习
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int firstNum = 12;
const int secondNum = 34;


int exchange(const int *ptr1, const int *ptr2);//全局。
/*
注意，声明函数时形参也要写，不能写成int exchange(）;这种样子。
否则会在调用函数时exchange(&firstNum, &secondNum);会出现error: too many arguments to function 'int exchange()'
意思是在调用是输入了太多的参数。
声明的时候是没有形参的，然而在调用时却输入了参数，当然会出现这个问题。
*/

int main(){
    // int exchange(const int *ptr1, const int *ptr2);//局部
    // int exchange();//这行时错误的
    exchange(&firstNum, &secondNum);
    return 0;
}

int exchange(const int *ptr1, const int *ptr2){
    const int *ptrTemp = ptr1;
    ptr1 = ptr2;
    ptr2 = ptrTemp;
    cout << "*ptr1:  " << *ptr1 << "  " << "ptr2:  " << 
    *ptr2 << endl;
    return 0;
}