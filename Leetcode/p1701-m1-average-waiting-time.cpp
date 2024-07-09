#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double averageWaitingTime(vector<vector<int>>& customers) {
    int n = customers.size();
    int currentTime = 0;
    double totalWaitingTime = 0;
    for (auto customer : customers) {
        int arrTime = customer[0];
        int cookTime = customer[1];
        currentTime = max(currentTime, arrTime);
        totalWaitingTime += (currentTime + cookTime) - arrTime;
        currentTime += cookTime;
    }
    return totalWaitingTime / n;
}

int main(){
    vector<vector<int>> vec = {{1, 2}, {3,4}, {6,7}};

    cout<<averageWaitingTime(vec);
    return 0;
}