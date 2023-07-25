#include <iostream>

class numbered {
public:
    numbered(); 
    numbered(const numbered&);
    int mysn;
private:
    static int unique;
};

int numbered::unique = 0;

numbered::numbered():mysn(unique++) {}

numbered::numbered(const numbered& nbd):mysn(unique++) {}

void f(const numbered& s) {std::cout << s.mysn << std::endl;}

int main() {
    numbered a, b = a, c = a;
    f(a); f(b); f(c);
    return 0;  
}