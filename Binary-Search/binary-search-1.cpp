#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int> vec, int key){
    int l = 0;
    int r = vec.size();
    while(l<r){
        int mid = l +(r-l)/2;

        if(key == vec[mid]){
            return 1;
        }
        if(key > vec[mid]){
            l = mid+1;
        }
        if(key<vec[mid]){
            r = mid-1;
        }
    }
    return 0;
}

int main(){
    vector<int> vec = {2, 5, 8, 9, 10, 15, 20 , 35};
    
    cout<<binarySearch(vec, 0);
    return 0;
}