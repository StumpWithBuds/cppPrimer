#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        vector<int>::iterator left = nums.begin();
        // vector<int>::iterator right = nums.end() - 1;
        
        for (left; left != nums.end(); left++) {
            if (*left == val) {
                nums.erase(left);
                count++;
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> vec = {3, 2, 2, 3};
    Solution sol;
    int target = 3;
    sol.removeElement(vec, target);
    return 0;
}