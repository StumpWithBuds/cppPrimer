/*
vector的初始化和范围for语句
*/
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1{1,2,3,4,5,6,7,8};
    vector<int> v2(v1);
    vector<int> v3(8,8);
    vector<int> v4(8);
    for(auto iter = v1.begin(); iter != v1.end(); ++iter){
        cout << *iter <<" ";
    }
    cout << endl; 
    for(auto iter = v2.begin(); iter != v2.end(); ++iter){
        cout << *iter <<" ";
    }
    cout << endl; 
    for(auto iter = v3.begin(); iter != v3.end(); ++iter){
        cout << *iter <<" ";
    }
    cout << endl; 
    for(auto iter = v4.begin(); iter != v4.end(); ++iter){
        cout << *iter <<" ";
    }
    cout << endl; 
    for(auto &r : v1){ //这里用引用是为了修改r的值。r只是局部变量，出了这个for循环就消亡了，
        r *= 2;        //所以是不能改变v1的值的。要改变v1的值，必须用引用。进一步理解可以看书P169
    }                  //范围for循环和传统for循环的等价
    for(int r : v1){
        cout << r << " ";
    }
    cout << endl;
    return 0;

}