#include <iostream>
#include <string>
#include <sys/time.h>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string());
    HasPtr(HasPtr &hp);
    ~HasPtr();
    HasPtr& operator=(HasPtr &hp);
    HasPtr(HasPtr &&hp) noexcept;
    HasPtr& operator=(HasPtr &&hp) noexcept;

    auto getPs() {return ps;}
private:
    std::string *ps;
    int i;
};

// HasPtr::HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
HasPtr::HasPtr(const std::string &s ): ps(new std::string(s)), i(0) {}
HasPtr::HasPtr(HasPtr &hp): ps(new std::string(*hp.ps)), i(hp.i) {}
HasPtr::~HasPtr() {delete ps;}
HasPtr& HasPtr::operator=(HasPtr &hp) {
    if (this != &hp) {
        std::string* temp_string = new std::string(*hp.ps);
        delete ps;
        ps = temp_string;
        i = hp.i;
    }
    return *this;
}
HasPtr::HasPtr(HasPtr &&hp) noexcept: ps(hp.ps), i(hp.i) {hp.ps = nullptr; hp.i = 0;}
HasPtr& HasPtr::operator=(HasPtr &&hp) noexcept  {
    if (this != &hp) {
        delete ps;
        ps = hp.ps;
        i = hp.i;
        hp.ps = nullptr;
        hp.i = 0;
    }
    return *this;
}

int main() {
    struct timeval start1, end1, start2, end2;

    HasPtr hp("123");
    std::cout << *hp.getPs() << std::endl;

    gettimeofday(&start2, NULL);
    HasPtr hp3(hp);
    gettimeofday(&end2, NULL);
     double duration2 = (end2.tv_sec - start2.tv_sec) + (end2.tv_usec - start2.tv_usec) / 1000000.0;
    std::cout << duration2 << std::endl;

    gettimeofday(&start1, NULL);
    HasPtr hp2(std::move(hp));
    gettimeofday(&end1, NULL);
     double duration1 = (end1.tv_sec - start1.tv_sec) + (end1.tv_usec - start1.tv_usec) / 1000000.0;
    std::cout << duration1 << std::endl;
    return 0;
}