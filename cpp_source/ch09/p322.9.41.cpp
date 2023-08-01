#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> vec{'a','c','d'};
    char a[] {'a','c','d'};
    std::string s(a, 3);
    std::cout << s[0] << *--s.end() << std::endl;
    std::string s2(vec.begin(), vec.end());
    std::cout << *s.begin() << s.back() << std::endl;

    std::string s3("123456789");
    std::string s4 = s3.substr(1, 3);
    // s4.push_back('1');
    
    std::cout << "s4: " << s4 << std::endl;
    return 0; 
}