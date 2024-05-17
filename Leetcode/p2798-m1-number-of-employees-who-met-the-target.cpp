#include<iostream>
#include<vector>

using namespace std;

int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int count=0;
    for(int i = 0; i<hours.size(); i++){
        if(hours[i] >= target) count++;
    }
    return count;
}

int main(){
    vector<int> vec1 = {3, 5, 2, 6, 7, 1, 4, 5, 5};
    cout<<numberOfEmployeesWhoMetTarget(vec1, 5);
    return 0;
}