#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution sol;
    // Input array
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int newLine = sol.removeElement(nums, val);
    cout << "{";
    for (int i = 0; i < newLine; i++) {
        cout << nums[i];
        if (i < newLine - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl; //expected output {2, 2}
    return 0;
}
