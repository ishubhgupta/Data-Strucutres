// Problem Statement 2: Common Elements
// You are given two lists of integers. Implement a program in C++ that finds and prints the common elements present in both lists. You can use vectors to store the elements.

// Input:

// The first line contains an integer 'n', the size of the first list.
// The second line contains 'n' space-separated integers representing the elements of the first list.
// The third line contains an integer 'm', the size of the second list.
// The fourth line contains 'm' space-separated integers representing the elements of the second list.
// Output:

// Print the common elements between the two lists.
// Example:
// Input:

// Copy code
// 5
// 2 5 8 3 1
// 4
// 3 7 2 5
// Output:

// Copy code
// 2 3 5

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;
    int n, m;
    cin>>n;
    for(int i=0; i<n;i++){
        int num;
        cin>>num;
        vec1.push_back(num);
    }
    cin>>m;
    for(int i=0; i<m;i++){
        int num;
        cin>>num;
        vec2.push_back(num);
    }

    for(int x : vec1) {
        for(int y : vec2) {
            if(y == x) {
                cout << y << " ";
                break;
            }
        }
    }

}