#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (n == 0) return -1;
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    string haystack = "sadbutsad";
    string needle = "sad";
    int index = s.strStr(haystack, needle);
    cout << index << endl; // Output: 0

    haystack = "leetcode";
    needle = "leeto";
    index = s.strStr(haystack, needle);
    cout << index << endl; // Output: -1

    haystack = "mississippi";
    needle = "issip";
    index = s.strStr(haystack, needle);
    cout << index << endl; // Output: 4

    return 0;
}
