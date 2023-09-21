#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--){
        digits[i] += carry;
        if (digits[i] < 10){
            return digits;
        } else {
            digits[i] = 0;
            carry = 1;
        }
    }
    if (carry == 1){
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main(){
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> digits3 = {9};

    vector<int> result1 = plusOne(digits1);
    vector<int> result2 = plusOne(digits2);
    vector<int> result3 = plusOne(digits3);

    for (int digit : result1){
        cout << digit;
    }
    cout << endl;

    for (int digit : result2){
        cout << digit;
    }
    cout << endl;

    for (int digit : result3){
        cout << digit;
    }
    cout << endl;

    return 0;
}