#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> vec;
    for(int i = 0; i<n;i++){
        string inp;
        cin>>inp;
        vec.push_back(inp);
    }

    int res = 0;
    for(auto x: vec){
        if(x == "X++" || x == "++X") res++;
        else res--;
    }
    cout<<res;
    return 0;
}