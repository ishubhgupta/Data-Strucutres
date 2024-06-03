#include <iostream>
#include <vector>

using namespace std;

int func(string s, string t){
    int i =0;
    int j =0;
    int m = s.length();
    int n = t.length();

    while(i<m && j<n){
        if(s[i] == t[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    if(j == n) return 0;
    else return n-j;
}

int main(){
    string s = "coaching";
    string t = "coding";

    cout<<func(s, t);
    return 0;
}