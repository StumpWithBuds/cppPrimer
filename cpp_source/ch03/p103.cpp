/*
数组的引用
引用数组
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int arr[10] = {1,2,3,4,5};
int main(){
    int (&arrRef)[10] = arr; //数组的引用，即arrRef时arr的一个别名
    cout<< arrRef[0] << endl;
    // int &refs[10] = /*错误：不存在引用的数组*/
    return 0;
}