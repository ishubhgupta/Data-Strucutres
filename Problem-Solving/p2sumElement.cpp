// ### Problem Statement 1:

// You are given a list of integers. Your task is to implement a program in C++ that finds and prints the sum of all the elements in the list using vectors.

// **Input:**
// - The first line contains an integer 'n', the size of the list.
// - The second line contains 'n' space-separated integers representing the elements of the list.

// **Output:**
// - Print the sum of all the elements in the list.

// ### Example:

// **Input:**
// ```
// 5
// 2 5 8 3 1
// ```

// Output:
// 19

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    int n;
    cin>>n;
    for(int i; i<n;i++){
        int num;
        cin>>num;
        vec1.push_back(num);
    }
    int sum = 0;
    for(int x:vec1){
        sum += x;
    }
    cout<<sum;
    return 0;
}

