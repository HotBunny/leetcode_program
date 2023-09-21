#include <iostream>
#include <vector>

using namespace std;

int countSpecialNumbers(int n) {
    // Convert the integer n to a string to work with its digits
    string s = to_string(n);
    int digits = s.size(); // Number of digits in n
    int ans = 0; // Initialize the answer to 0

    // Count special numbers with fewer digits
    for (int i = 1; i < digits; i++) {
        int x = 1, k = 9;
        for (int j = 0; j < i - 1; j++) {
            x *= k;
            k--;
        }
        ans += 9 * x;
    }

    vector<int> done(10, 0); // Track used digits (0 to 9)

    for (int i = 0; i < digits; i++) {
        int smaller = 0;
        
        // Count smaller digits that are not used yet
        for (int j = 0; j < s[i] - '0'; j++) {
            if (!done[j]) {
                smaller++;
            }
        }

        // If it's the first digit and greater than 0, reduce smaller by 1
        if (i == 0 && s[i] > '0') {
            smaller--;
        }

        int aage = 1, rem = 10 - i - 1;

        // Calculate the number of possibilities for the remaining digits
        for (int j = i + 1; j < digits; j++) {
            aage *= rem;
            rem--;
        }

        // Update the answer by multiplying smaller and aage
        ans += smaller * aage;

        // Mark the current digit as used
        if (!done[s[i] - '0']) {
            done[s[i] - '0'] = 1;
        } else {
            // If a digit is repeated, return the current answer
            return ans;
        }
    }

    // Add 1 to the answer for the number itself, as it's special
    return ans + 1;
}

int main() {
    int n = 135;
    int specialCount = countSpecialNumbers(n);
    cout << "Number of special integers in the range [1, " << n << "]: " << specialCount << endl;
    return 0;
}
