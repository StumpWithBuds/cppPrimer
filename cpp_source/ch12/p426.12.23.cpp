#include <iostream>
#include <memory>
#include <cstring>

char* func(const char* s1, const char* s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    char* r = new char[len1 + len2]();
    strcat(r, s1);
    strcat(r, s2);
	// std::cout << r << std::endl;
    return r;
    
}

char* func2(const std::string s1, const std::string s2) {
    int len = s1.size() + s2.size();
    char* r(new char[len]);
    strcpy(r, (s1 + s2).c_str());
    return r;
}

int main() {
    char* s1 = "abcd";
    char* s2 = "efg";
    char* r = func(s1, s2);
    std::cout << r << std::endl;

    std::string str1 = "hello";
    std::string str2 = "hello";
    char* r2 = func2(str1, str2);
    std::cout << r2 << std::endl;

    return 0;
}