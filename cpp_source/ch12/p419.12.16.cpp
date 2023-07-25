#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p (new int(12));
    // std::unique_ptr<int> q(p);
    return 0;
}