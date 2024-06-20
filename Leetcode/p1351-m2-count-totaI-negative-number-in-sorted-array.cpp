#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ans = 0 ;
    for(int i = 0; i < grid.size(); i++){
        sort(grid[i].begin(), grid[i].end());
        ans += lower_bound(grid[i].begin(), grid[i].end(), 0) - grid[i].begin();
    }
    return ans;

}

int main(){
    vector<vector<int>> grid = {{4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3}};

    cout<<countNegatives(grid);
}