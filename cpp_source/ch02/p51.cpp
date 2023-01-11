/*p51练习2.18*/

#include <iostream>

int main(){
    int *ptr = nullptr;
    int val = 10;
    ptr = &val;
    *ptr = 12;
    ptr = nullptr;
    std::cout << val << " " << ptr << std::endl;
    return 0;
}