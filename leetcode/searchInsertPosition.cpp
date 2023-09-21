#include <iostream>
#include <vector>

using namespace std;



//binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = sol.searchInsert(nums, target);
    cout << index << endl; // Output: 2

    nums = {1, 3, 5, 6};
    target = 2;
    index = sol.searchInsert(nums, target);
    cout << index << endl; // Output: 1

    nums = {1, 3, 5, 6};
    target = 7;
    index = sol.searchInsert(nums, target);
    cout << index << endl; // Output: 4

    return 0;
}
