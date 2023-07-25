#include <iostream>
#include <string>

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv: public Base{
    int f() {return prot_mem;}
};

struct Priv_Derv: private Base{
    int f1() const {return prot_mem;}
};

struct Prot_Derv: protected Base{
    int f2() const {return prot_mem;}
};

int main() {
    Pub_Derv d1; Priv_Derv d2; Prot_Derv d3;
    Base* p = &d1;
    // p = &d2;
    // p = &d3;
    return 0; 
}