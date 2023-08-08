#include <memory>
#include <iostream>

class DebugDelete {
public:
    DebugDelete(): os(std::cout) {} 
    // DebugDelete() {};
    DebugDelete(std::ostream &os): os(os) {}
    template <typename T> void operator() (T p) const {
        delete p;
        os << "delete ptr" << std::endl;
    } 
private:
    std::ostream& os;
};

int main() {
    float* p = new float(3.12);
    // DebugDelete dp(std::cout);
    DebugDelete dp;
    dp(p);
    return 0;
}
