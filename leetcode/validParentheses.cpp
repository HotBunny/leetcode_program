#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (mapping.count(c)) {  // check if the character is a closing bracket
                if (st.empty() || st.top() != mapping[c]) {
                    return false;
                }
                st.pop();
            } else {  // this is an opening bracket
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    cout << boolalpha << solution.isValid("()") << endl;  // true
    cout << boolalpha << solution.isValid("()[]{}") << endl;  // true
    cout << boolalpha << solution.isValid("(]") << endl;  // false
    return 0;
}
