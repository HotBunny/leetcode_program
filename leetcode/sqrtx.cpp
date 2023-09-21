#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 1, right = x, ans;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int x = 4;
    int ans = sol.mySqrt(x);
    cout << "The floor square root of " << x << " is " << ans << endl;
    return 0;
}
