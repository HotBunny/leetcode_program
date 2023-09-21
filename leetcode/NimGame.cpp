#include <iostream>

using namespace std;

bool canWinNim(int n){
    return (n % 4 != 0);
}

int main(){
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    if (canWinNim(n)){
        cout << "You can win the game!" << endl;
    } else {
        cout << "Sorry, you will lose the game." << endl;
    }
    return 0;
}