#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarraywithsumk(vector<int> vec, int k){
    map<int, int> hashmap;
    hashmap[0] = 1;
    int prefixSum = 0;
    int count = 0;
    int n = vec.size();

    for(int i =0;i<n;i++){
        prefixSum += vec[i];
        int remove = prefixSum-k;
        count += hashmap[remove];
        hashmap[prefixSum] += 1;
    }

    return count;
}

int subarraysumdivisblebyk(vector<int> vec, int k){
    map<int, int> hashmap;

    hashmap[0] = 1;
    int n = vec.size();
    int prefixSum = 0;
    int count = 0;
    for(int i = 0; i<n;i++){
        prefixSum += vec[i];
        int div = prefixSum/k;
        count += hashmap[div];
        hashmap[prefixSum] += 1;
    }

    return count;
}
int main(){
    vector<int> vec = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout<<subarraywithsumk(vec, 3)<<endl;

    cout<<subarraysumdivisblebyk(vec, 3)<<endl;
    return 0;
}