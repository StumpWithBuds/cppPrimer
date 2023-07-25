#include <iostream>
#include <cstring>
using namespace std;

bool lengthCompare(const string &a, const string &b) {
    if (a > b) return true;
    else return false;
}

bool (*pf) (const string &, const string &);

int main() {
    string a = "abcd", b = "bcde";
    pf = lengthCompare;
    bool judgement = pf(a, b);
    std::cout << judgement << std::endl;
    return 0;
}

