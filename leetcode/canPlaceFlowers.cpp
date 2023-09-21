#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n){
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++){
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
            flowerbed[i] = 1;
            count++;
        }
    }
    return count >= n;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool canPlace = canPlaceFlowers(flowerbed, n);

    if (canPlace) {
        cout << "It is possible to plant " << n << " new flowers." << endl;
    } else {
        cout << "It is NOT possible to plant " << n << " new flowers." << endl;
    }

    return 0;
}
