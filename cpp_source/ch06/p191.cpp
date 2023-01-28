/*
体会加入const的参数传递
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void reset(int &i); // 函数的声明，因为函数的定义在main函数的后面
void resetPtr(int *p); //函数的声明，因为函数的定义在main函数的后面
int main(){
    int i = 10;
    const int ci = i;
    const int &iRef = i;
    const  string &stringRef = "sting";
    //string &stringRef2 = "sting"; //buggy
    // int &ref = ci; //buggy
    // int &ref = 85; //buggy

    // resetPtr(&i);
    // reset(i);
    // reset(ci); // buggy ,same as "int &ref = ci";
    cout << "i: " << i << endl;
    cout << "string ref: " << stringRef << endl;
    return 0;
}

void reset (int &i){
    i = 0;
}

void resetPtr (int *ip){
    *ip = 0;
    ip = 0; //只改变了ip的局部拷贝，实参没有改变
}