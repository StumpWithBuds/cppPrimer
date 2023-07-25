#include <iostream>
#include <string>


class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) {
        std::cout << "HasPtr(const std::string &s = std::string())" << std::endl;
     }
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { 
        ++*use; 
        std::cout << "HasPtr(const HasPtr &hp)" << std::endl;
    }
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        std::cout << "HasPtr& operator=(const HasPtr &rhs)" << std::endl;
        return *this;
    }
    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
            std::cout << "~HasPtr()" << std::endl;
        }
    } 

    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(HasPtr&, HasPtr&);

    std::string* getPs() {return ps;}
    size_t* getUse() {return use;}

private:
    std::string *ps;
    int i;
    size_t *use;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
    std::cout << "void HasPtr::swap" << std::endl;
}

bool operator< (HasPtr& hp1, HasPtr& hp2) {
    return *hp1.getPs() < *hp2.getPs();
}

void func() {
    HasPtr hp1("123");
    HasPtr hp2 = hp1;
    std::cout << *hp2.getPs() << std::endl;
    std::cout << *hp1.getUse() << std::endl;
}
int main() {
    // func();
    HasPtr hp1("123456");
    HasPtr hp2("789");
    swap(hp1, hp2);
    std::cout << *hp1.getPs() << std::endl;
    bool judge = hp1 < hp2;
    std::cout << "judge: " << judge << std::endl;
    return 0;
}
