#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    cin>>name;
    set<char> unique;
    for(auto c:name){
        unique.insert(c);
    }

    int size = unique.size();
    if(size%2==0){
        cout<<"CHAT WITH HER!";
    }
    else{
        cout<<"IGNORE HIM!";
    }
    return 0;
}