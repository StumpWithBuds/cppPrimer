/*
练习6.17
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isUpper(const string &s){
    if(s.begin() == s.end()) return false;
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(isupper(*iter) > 0){
            return true;
        }
    }
    return false;
}

bool upper(string &s){
    if(s.begin() == s.end()) return false;
    for(auto iter = s.begin(); iter != s.end(); ++iter){
        if(isupper(*iter) > 0){
            *iter = tolower(*iter);
        }
    }
    return true;
}

int main(){
    string s = "AGSFGgsAFG";
    cout << "origin string: " << s << endl;
    if(isUpper(s) == true){
        upper(s);
    }
    cout << "lower string: " << s << endl;
    return 0;
}