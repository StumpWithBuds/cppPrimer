#include <iostream>
#include <list>
#include <forward_list>
#include <string>

void print(std::forward_list<int> fl) {
    for(auto cur = fl.begin(), pre = fl.before_begin(); cur != fl.end(); ++cur) {
        std::cout << *cur << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::forward_list<int> fl{1,2,3,4,5,6,7,8,9,10};
    std::forward_list<int>::iterator cur = fl.begin();
    std::forward_list<int>::iterator pre = fl.before_begin();
    while (cur != fl.end()) {
        if (*cur % 2 == 0) {
            cur = fl.erase_after(pre);
        }
        else {
            pre = cur;
            ++cur;
        }
    }
    print(fl);
    return 0;
}