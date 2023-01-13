#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const vector<string> vs = {"1", "2", "3", "4", "5", "6","7"};

auto biSearch (const vector<string> &text, string sought){
    auto beg = text.begin();
    auto end = text.end();
    auto mid = text.begin() + (end - beg) / 2;
    while (mid != end && *mid != sought){
        if (sought < *mid)
            end = mid;
        else 
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    if(*mid == sought)
        return mid;
    else
        return text.end();
} 

int main(){
    string sought = "1";
    auto iter = biSearch(vs,sought);
    cout << *iter << endl;
    return 0;
}