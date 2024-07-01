#include<iostream>
#include<vector>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i<n-2;i++){
        if(arr[i]%2 == 1 && arr[i+1]%2 == 1 && arr[i+2]%2 == 1){
            return true;
            break;
        }
    }
    return false;
}

int main(){
    vector<int> vec1 ={1,2,34,3,4,5,7,23,12};
    cout<<threeConsecutiveOdds(vec1);
    return 0;
}