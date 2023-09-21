#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int pairs = 0;
        int left = 0;
        for (auto& [num, count] : freq) {
            pairs += count / 2;
            left += count % 2;
        }
        return {pairs, left};    
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 1, 3, 2, 2};
    Solution sol;
    vector<int> result = sol.numberOfPairs(nums);
    cout << "Pairs: " << result[0] << endl;
    cout << "Left: " << result[1] << endl;
    return 0;

}