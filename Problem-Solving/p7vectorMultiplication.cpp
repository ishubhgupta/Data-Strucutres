// Problem Statement 7: Vector Multiplication
// You are given two lists of integers of the same size. Implement a program in C++ that multiplies the corresponding elements of the two lists and prints the result using vectors.

// Input:

// The first line contains an integer 'n', the size of the lists.
// The second line contains 'n' space-separated integers representing the elements of the first list.
// The third line contains 'n' space-separated integers representing the elements of the second list.
// Output:

// Print the list obtained by multiplying corresponding elements.
// Example:
// Input:

// Copy code
// 4
// 1 2 3 4
// 5 6 7 8
// Output:

// Copy code
// 5 12 21 32


#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec1, vec2, vec3;
    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        vec2.push_back(num);
    }

    vec3.resize(max(n,m));

    for(int i=0; i<max(n,m); i++){
        int mul =1;
        if(i<n){
            mul = mul*vec1[i];
        }
        if(i<m){
            mul = mul*vec2[i];
        }
        vec3[i] = mul;
    }

    for(int x:vec3){
        cout<<x<<" ";
    }
}