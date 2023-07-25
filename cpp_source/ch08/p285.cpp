#include <iostream>
#include <string>
#include <vector>

void func(const std::string& fileName, std::vector<std::string> vec) {
    std::ifstream ifs(fileName);
    if (ifs) {
        std::string buf;
        while(getline(ifs, buf)) {
            vec.push_back(buf);
        }
    }
}

void func2(const std::string& fileName, std::vector<std::string> vec) {
    std::ifstream ifs(fileName);
    if (ifs) {
        std::string buf;
        while(ifs >> buf) {
            vec.push_back(buf);
        }
    }
}


