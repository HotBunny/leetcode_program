#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);  // create a vector of size n+1 and initialize all elements to 0
        dp[0] = 1;  // base case: there is 1 way to climb 0 stairs
        dp[1] = 1;  // base case: there is 1 way to climb 1 stair

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];  // number of ways to climb i stairs is sum of ways to climb (i-1) stairs and (i-2) stairs
        }

        return dp[n];  // return the number of ways to climb n stairs
    }
};

int main() {
    Solution sol;

    // test cases
    cout << sol.climbStairs(2) << endl;  // expected output: 2
    cout << sol.climbStairs(3) << endl;  // expected output: 3
    cout << sol.climbStairs(4) << endl;  // expected output: 5
    cout << sol.climbStairs(5) << endl;  // expected output: 8

    return 0;
}
