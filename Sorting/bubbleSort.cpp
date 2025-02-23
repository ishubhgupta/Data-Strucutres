#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &vec){
    int n = vec.size();
    
    for(int i=n-1; i>=1; i--){
        bool didSwapped = false;
        for(int j= 0; j<i; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                didSwapped = true;
            }
        }
        if(!didSwapped) break;
    }
}

int main() {
    vector<int> vec = {4, 5, 78, 69, 88, 37, 52, 90};
    bubbleSort(vec);
    for(int it: vec){
        cout<<it<<" ";
    }
    return 0;
}