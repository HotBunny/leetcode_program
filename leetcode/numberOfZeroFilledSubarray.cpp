#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int zeroCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
            }else{
                ans += (long long)zeroCount*(zeroCount+1)/2;
                zeroCount = 0;
            }
        }
        ans += (long long)zeroCount*(zeroCount+1)/2;
        return ans;
    }
};




int main() {
    vector<int> nums1 {1, 3, 0, 0, 2, 0, 0, 4};
    Solution sol1;
    cout << sol1.zeroFilledSubarray(nums1) << endl; // output: 6
    
    vector<int> nums2 {0, 0, 0, 2, 0, 0};
    Solution sol2;
    cout << sol2.zeroFilledSubarray(nums2) << endl; // output: 9
    
    vector<int> nums3 {2, 10, 2019};
    Solution sol3;
    cout << sol3.zeroFilledSubarray(nums3) << endl; // output: 0
    
    return 0;
}
