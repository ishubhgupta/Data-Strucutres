#include <bits/stdc++.h>
using namespace std;

int main() {
    int year = 0;
    int limak, bob;
    cin>>limak>>bob;
    
    while(limak <= bob){
        limak *= 3;
        bob *= 2;
        year++;
    }
    cout<<year;
    return 0;
}