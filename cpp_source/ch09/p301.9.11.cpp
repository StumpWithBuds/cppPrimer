#include <vector>

int main() {
    std::vector<int> v1;
    std::vector<int> v2(10,3);
    std::vector<int> v6(v2);
    std::vector<int> v3(v2.begin(), v2.end());
    std::vector<int> v4 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v5(10);
}