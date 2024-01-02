// Problem Statement 6: Vector Addition
// You are given two lists of integers of the same size. Implement a program in C++ that adds the corresponding elements of the two lists and prints the result using vectors.

// Input:

// The first line contains an integer 'n', the size of the lists.
// The second line contains 'n' space-separated integers representing the elements of the first list.
// The third line contains 'n' space-separated integers representing the elements of the second list.
// Output:

// Print the list obtained by adding corresponding elements.
// Example:
// Input:

// Copy code
// 4
// 1 2 3 4
// 5 6 7 8
// Output:

// Copy code
// 6 8 10 12


#include<iostream>
#include<vector>
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

    vec3.resize(max(n, m));

    for(int i = 0; i < max(n, m); i++){
        int sum = 0;
        if (i < n) {
            sum += vec1[i];
        }
        if (i < m) {
            sum += vec2[i];
        }

        vec3[i] = sum;
    }

    for(int x : vec3){
        cout << x << " ";
    }

    return 0;
}
