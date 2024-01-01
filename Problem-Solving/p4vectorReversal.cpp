// Problem Statement 4: Vector Reversal
// You are given a list of integers. Implement a program in C++ that reverses the order of elements in the list using vectors.

// Input:

// The first line contains an integer 'n', the size of the list.
// The second line contains 'n' space-separated integers representing the elements of the list.
// Output:

// Print the reversed list.
// Example:
// Input:

// Copy code
// 5
// 1 2 3 4 5
// Output:

// Copy code
// 5 4 3 2 1


#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec1.push_back(num);
    }
    
    for(int i = n - 1; i >= 0; i--){
        vec2.push_back(vec1[i]);
    }

    for(int x : vec2){
        cout << x << " ";
    }

    return 0;
}
