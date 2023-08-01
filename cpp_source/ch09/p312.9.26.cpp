#include <vector>
#include <list>
#include <iostream>


int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    std::vector<int> v1(ia, std::end(ia));
    std::list<int> l1(ia, std::end(ia));
    for (std::vector<int>::iterator iter = v1.begin(); iter != v1.end();) {
        if (*iter % 2 == 0) {
            iter = v1.erase(iter);
        }
        else 
            ++iter;
    }
    return 0;
}