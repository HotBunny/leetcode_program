#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k){
    int left = 0, right = arr.size() - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - mid - 1;
        if (missing < k){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + k;
}


int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive integer is: " << result << endl;
    return 0;
}