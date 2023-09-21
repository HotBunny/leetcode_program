#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
        return "";
    string prefix = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        string curr = strs[i];
        int j = 0;
        while(j < prefix.length() && j < curr.length() && prefix[j] == curr[j]) {
            j++;
        }
        prefix = prefix.substr(0, j); // update prefix to common prefix at this iteration
    }
    return prefix;
}



int main() {
    vector<string> strs = {"flower", "flow", "flight"}; 
    string prefix = longestCommonPrefix(strs);
    cout << "Longest common prefix: " << prefix << endl; // Output: "fl"
    
    return 0;
}
