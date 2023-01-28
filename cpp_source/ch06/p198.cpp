#include <iostream>
#include <string>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::initializer_list;

void error_msg(initializer_list<string> il){
    for(auto beg = il.begin(); beg != il.end(); ++beg){
        cout << *beg << " ";
    }
    cout << endl;
}

int main(){
    string expected = "abcd", actual = "abcd";
    if(expected == actual)
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "okay"});
    
    return 0;
}

