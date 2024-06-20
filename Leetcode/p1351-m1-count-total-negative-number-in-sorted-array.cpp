#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int count=0;
    for(auto row: grid){
        int n = row.size();
        for(int i =0;i<n;i++){
            if(row[i]<0){
                count++;
            }
        }


    }
    return count;
}

int main(){
    vector<vector<int>> grid = {{4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3}};

    cout<<countNegatives(grid);
}