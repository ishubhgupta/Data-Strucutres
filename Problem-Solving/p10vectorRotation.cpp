// Problem Statement 11: Vector Rotation
// You are given a vector of integers. Implement a program in C++ that rotates the elements of the vector to the left by a given number of positions.

// Input:

// The first line contains an integer 'n', the size of the vector.
// The second line contains 'n' space-separated integers representing the elements of the vector.
// The third line contains an integer 'k', the number of positions to rotate the vector to the left.
// Output:

// Print the vector after rotating it to the left by 'k' positions.
// Example:
// Input:

// Copy code
// 6
// 1 2 3 4 5 6
// 2
// Output:

// Copy code
// 3 4 5 6 1 2

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec1;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vec1.push_back(num);
    }

    int k;
    cin>>k;

    for(int i=0; i<k;i++){
        int temp = vec1[0];
        vec1.erase(vec1.begin());
        vec1.push_back(temp);
    }
    for(int x : vec1){
        cout<<x<<" ";
    }
}