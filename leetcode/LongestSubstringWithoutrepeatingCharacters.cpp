#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s){
    int n = s.length();
    int i = 0, j = 0, max_len = 0;
    unordered_set<char> seen;

    while (i < n && j < n){
        if (seen.find(s[j]) == seen.end()){
            seen.insert(s[j++]);
            max_len = max(max_len, j - i);
        } else {
            seen.erase(s[i++]);
        }
    }

    return max_len;
}

int main(){
    string s = "pwwkew";
    int length = lengthOfLongestSubstring(s);
    cout << "Longest substring: " << length << endl;

    return 0;
}