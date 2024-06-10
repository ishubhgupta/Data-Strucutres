#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> vec = heights;
    sort(vec.begin(), vec.end());
    int n = heights.size();
    int count =0;
    for(int i = 0;i<n;i++){
        if(vec[i] != heights[i]) count++;
    }
    return count;
}

int main(){
    vector <int> vec = {3,5, 3, 4, 8, 9, 3};
    cout<<heightChecker(vec);
    return 0;
}