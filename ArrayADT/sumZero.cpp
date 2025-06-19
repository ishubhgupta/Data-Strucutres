#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {-3, 3, 0, 2};
    int count = 0;
    unordered_set<int> prefixSum;
    int sum = 0;
    for(int i = 0; i< vec.size(); i++){
        sum += vec[i];
        if(sum == 0 || prefixSum.find(sum)!= prefixSum.end()){
            count++;
        }
        prefixSum.insert(sum);
    }
    cout<<count;
    return 0;
}