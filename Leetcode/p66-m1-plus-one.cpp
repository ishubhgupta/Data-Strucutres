#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// vector<int> plusOne(vector<int> digit){
//     vector<int> vec;
//     int n = digit.size();
//     int num = 0;
//     for(int i = n-1; i >= 0; i--){
//         num += digit[i] * pow(10, n-1 - i);
//     }

//     num += 1;
//     while (num > 0) {
//         int ld = num % 10;
//         vec.insert(vec.begin(), ld);
//         num /= 10;
//     }
//     return vec;
// }

// int main(){
//     vector<int> vec1 = {1, 2, 3};
//     vec1 = plusOne(vec1);
//     for(auto x : vec1){
//         cout << x << " ";
//     }
//     return 0;
// }


vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    digits[n - 1]++;
    
    for (int i = n - 1; i > 0 && digits[i] == 10; --i) {
        digits[i] = 0;
        digits[i - 1]++;
    }
    
    if (digits[0] == 10) {
        digits[0] = 0;
        digits.insert(digits.begin(), 1);
    }
    
    return digits;
}

int main(){
    vector<int> vec1 = {1, 2, 3, 0};
    vec1 = plusOne(vec1);
    for(auto x : vec1){
        cout << x << " ";
    }
    return 0;
}