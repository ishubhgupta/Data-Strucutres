#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &vec){
    int n = vec.size();
    for(int i = 0; i< n-1; i++){
        int j = i;
        while(j>0 && (vec[j]<vec[j-1])){
            swap(vec[j], vec[j-1]);
            j--;
        }
    }
}

int main() {
    vector<int> vec = {4, 5, 2, 8, 9, 5, 7};
    insertionSort(vec);
    for( int it: vec){
        cout<<it<<" ";
    }
    return 0;
}