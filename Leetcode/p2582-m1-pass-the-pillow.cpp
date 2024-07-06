#include<iostream>
#include<vector>

using namespace std;


int passThePillow(int n, int time) {
    int i = 1;
    int dir = 1;
    int res = 1;
    while(i<=time){
        res += dir;
        i++;
        if(res == n || res == 1){
            dir = -dir;
        }
    }
    return res;
}


int main(){
    cout<<passThePillow(4, 5);
}