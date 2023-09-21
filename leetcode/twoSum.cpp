#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> visited;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int n = nums[i];
            int complement = target - n;
            if (visited.count(complement)) {
                return {visited[complement], i};
            }
            visited[n] = i;  // assume that each input would have exactly one solution
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution solution;
    vector<int> indices = solution.twoSum(nums, target);

    cout << "Indices of elements that add up to " << target << ": [" << indices[0] << ", " << indices[1] << "]" << endl;

    return 0;
}
