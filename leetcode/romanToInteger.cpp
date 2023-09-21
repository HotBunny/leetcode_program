#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInt(string s){
    unordered_map<char, int> values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i < n -1 && values[s[i]] < values[s[i+1]]){
            result -= values[s[i]];
        }else{
            result += values[s[i]];
        }
    }
    return result;
}

int main(){
    string s = "MCMXCIV";
    int result = romanToInt(s);
    cout << "The integer value of " << s << " is " << result << endl;
    return 0;
}