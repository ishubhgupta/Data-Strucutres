// Problem Statement 5: Vector Doubling
// You are given a list of integers. Implement a program in C++ that doubles each element in the list using vectors.

// Input:

// The first line contains an integer 'n', the size of the list.
// The second line contains 'n' space-separated integers representing the elements of the list.
// Output:

// Print the list after doubling each element.
// Example:
// Input:

// Copy code
// 3
// 5 10 15
// Output:

// Copy code
// 10 20 30


#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int num;
        cin>>num;
        vec1.push_back(num);
    }

    for(int x:vec1){
        cout<<2* x<<" ";
    }

    return 0;
}