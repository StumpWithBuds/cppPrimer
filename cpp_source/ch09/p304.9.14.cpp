#include <string>
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<char*> l1 {"123", "456", "789"};
    // std::vector<std::string> v1(l1.begin(), l1.end());
    std::vector<std::string> v1;
    v1.assign(l1.begin(), l1.end());
    std::cout << *v1.begin() << std::endl;
    return 0;
}