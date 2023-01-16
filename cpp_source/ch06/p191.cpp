/*
体会加入const的参数传递
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset(int &i);
void resetPtr(int *p);
int main(){
    int i = 10;
    const int ci = i;
    const int &iRef = i;
    // int &ref = ci; //buggy
    // int &ref = 85; //buggy

    // resetPtr(&i);
    // reset(i);
    // reset(ci); // buggy ,same as "int &ref = ci";
    cout << "i: " << i << endl;
    return 0;
}

void reset (int &i){
    i = 0;
}

void resetPtr (int *ip){
    *ip = 0;
    ip = 0; //只改变了ip的局部拷贝，实参没有改变
}