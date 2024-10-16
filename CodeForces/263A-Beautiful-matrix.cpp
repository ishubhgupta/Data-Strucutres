#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            int val;
            cin>>val;
            if(val == 1){
                cout<<abs(i-2)+abs(j-2);
                break;
            }
        }
    }
    
    return 0;
}