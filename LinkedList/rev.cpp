#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

int findPermutationDifference(string s, string t){
    int n = s.length();
    int sum=0;
    for(int i =0; i<n;i++){
        for(int j = 0; j<n;j++){
            if(t[j] == s[i]){
                sum += abs(i-j);
                break;
            }
        }
    }
    return sum;
}

int main(){
    string s = "abcde";
    string t = "edbac";
    cout<<findPermutationDifference(s, t);
}
