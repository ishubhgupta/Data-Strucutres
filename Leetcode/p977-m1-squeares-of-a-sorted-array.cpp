#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> square;
    for(auto x: nums){
        square.push_back( x*x );
    }
    sort(square.begin(), square.end());
    return square;
}


int main(){
    vector<int> vec1 = {-4, -1, 0, 0,  3, 10};
    vec1 = sortedSquares(vec1);
    for(auto x: vec1){
        cout<<x<<" ";
    }
    return 0;
}