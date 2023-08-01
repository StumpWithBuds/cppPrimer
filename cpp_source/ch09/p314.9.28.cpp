#include <iostream>
#include <forward_list>
#include <string>

void func(std::forward_list<std::string>& fl, std::string s1, std::string s2) {
    for (std::forward_list<std::string>::iterator pre = fl.before_begin(), cur = fl.begin();
    cur != fl.end();){
        if (*cur == s1) {
            pre = cur;
            cur = fl.insert_after(cur, s2);
            return;
        }
        else {
            ++cur;
            ++pre;
        }
    }
    return;
}

void print(std::forward_list<std::string> fl) {
    for(std::forward_list<std::string>::const_iterator iter = fl.cbegin(); iter != fl.cend(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::forward_list<std::string> fl{"123","456","789"};
    func(fl,"123","147");
    print(fl);
    return 0;
}