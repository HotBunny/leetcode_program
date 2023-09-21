class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0; // use long long to avoid integer overflow
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                count += (right - left + 1) * (right - left + 2) / 2;
            }
            right++;
            if (nums[left] == 0) {
                left++;
            }
            while (left < right && nums[left] != 0) {
                left++;
            }
        }
        return count;
    }
};