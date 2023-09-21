#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};

int main() {
    string input = "PAYPALISHIRING";
    int numRows = 3;

    Solution solution; // Create an instance of the Solution class
    string output = solution.convert(input, numRows);

    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;

    return 0;
}
