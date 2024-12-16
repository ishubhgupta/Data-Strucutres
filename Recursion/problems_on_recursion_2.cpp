#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int l, int r){
    if(l>=r) return;
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reverseArray(arr, l+1, r-1);
}

void isPalindrome(string arr, int l, int r, bool &res){
    if(l>=r) return;
    if(arr[l] == arr[r]){
        return isPalindrome(arr, l+1, r-1, res);
    }
    res = false;
}

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, arr.size()-1);
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
    bool res = true;
    isPalindrome("nman", 0, 4, res);
    cout<<res<<endl;

    cout<<fibonacci(6);
    return 0;
}