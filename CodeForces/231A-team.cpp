#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> vec;
    int n;
    cin>>n;
    int a, b, c, count = 0;
    for(int i = 0;i<n;i++){
        cin>>a>>b>>c;
        if(a+b+c>=2){
            count++;
        }
    }
    cout<<count;
    return 0;
}