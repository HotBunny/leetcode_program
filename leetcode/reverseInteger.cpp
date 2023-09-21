    #include <iostream>
#include <climits>

using namespace std;

// Function to reverse the digits of a signed 32-bit integer
// Returns 0 if the reversed integer is outside the range of a signed 32-bit integer
int reverse(int x){
    int rev = 0;
    while (x != 0){
        int pop = x % 10;
        x /= 10;
        // Check for overflow or underflow
        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main(){
    int x = -123;
    cout << "Reversed " << x << " is " << reverse(x) << endl;

    int a = 123;
    cout << "Reversed " << a << " is " << reverse(a) << endl;

    int b = 120;
    cout << "Reversed " << b << " is " << reverse(b) << endl;

    return 0;
}
