#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) {
        return s; // If the string is empty or has only one character, it's a palindrome itself
    }

    vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] represents whether s[i:j] is a palindrome
    int start = 0; // Start index of the longest palindromic substring found
    int maxLength = 1; // Length of the longest palindromic substring found

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for palindromes of length 3 or more
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1; // End index of current substring

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string input = "babad";
    string longestPalindromicSubstring = longestPalindrome(input);

    cout << "Input: " << input << endl;
    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring << endl;

    return 0;
}
