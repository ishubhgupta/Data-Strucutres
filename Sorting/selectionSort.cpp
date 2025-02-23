#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& vec){
    int n = vec.size();
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(vec[j] < vec[minIndex]){
                minIndex = j;   
            }
        }
        swap(vec[i], vec[minIndex]);
    }
}

int main() {
    vector<int> vec = {38, 3, 6, 87, 89, 45, 2, 67, 88};
    selectionSort(vec);
    for(int it: vec){
        cout<<it<<" ";
    }
    return 0;
}