#include <bits/stdc++.h>
using namespace std;

void prin(int n){
    if(n<1) return;
    cout<<"Shubh Gupta"<<endl;
    prin(n-1);
}

void printLinear(int n){
    if(n>5) return;
    
    printLinear(n+1);
    cout<<n<<endl;
    
}

int sum(int n){
    if(n<1) return 0;
    return n + sum(n-1);
}

void revArr(vector<int> inp, int i, int n, vector<int> &res){
    if(i>=n) return;
    revArr(inp, i+1, n, res);
    res.push_back(inp[i]);
}

void revArrSwap(vector<int> &inp, int l, int r){
    if(l>r) return;
    swap(inp[l], inp[r]);
    revArrSwap(inp, l+1, r-1);
}

bool ispalin(string s, int l, int r){
    if(l>=r) return true;
    if(s[l] == s[r]) return ispalin(s, l+1, r-1);
    else return false;
}


int fab(int n){
    if(n<=1) return n;
    return fab(n-1)+(n-2);
}

void sub(vector<int> vec, int idx, vector<int> &imp){
    if(idx >= vec.size()){
        for(int i = 0; i<imp.size(); i++){
            cout<<imp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    imp.push_back(vec[idx]);
    sub(vec, idx+1, imp);
    imp.pop_back();
    
    sub(vec, idx+1, imp);

}

void subSumK(vector<int> vec, int idx, vector<int> imp, int k, int sum){
    if(idx>=vec.size()){
        if(sum == k){
            for(int i = 0; i<imp.size(); i++) cout<<imp[i]<<" ";
            cout<<endl;
        }       
        return;
    }
    imp.push_back(vec[idx]);
    subSumK(vec, idx+1, imp, k, sum+vec[idx]);
    imp.pop_back();
    subSumK(vec, idx+1, imp, k, sum);

}
int main() {
    // printLinear(1);
    // cout<<sum(5)<<endl;
    vector<int> arr = {5, 6, 3, 4, 3};
    // vector<int> res;
    // revArr(arr, 0, 5, res);

    // revArrSwap(res, 0, 4);
    // for(int i = 0; i<5; i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    // cout<<ispalin("mad4m", 0, 4)<<endl;

    // for(int i = 0; i< 5; i++){
    //     cout<<fab(i)<<" ";
    // }
    vector<int> ans;
    
    // sub(arr, 0, ans);

    subSumK(arr, 0, ans, 14, 0);

    return 0;
}