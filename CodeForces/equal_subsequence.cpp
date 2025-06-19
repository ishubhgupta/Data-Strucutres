#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T>0){
        int n, k;
        cin>>n>>k;

        int zeros = n-k;
        string ans = "";

        int front_zeros = zeros/2;
        for(int i = 0; i < front_zeros; i++){
            ans += "0";
        }

        for(int i = 0; i < k; i++){
            ans += "1";
        }

        int back_zeros = zeros - front_zeros;
        for(int i = 0; i < back_zeros; i++){
            ans += "0";
        }

        cout<<ans<<endl;
        T--;
    }
    return 0;
}