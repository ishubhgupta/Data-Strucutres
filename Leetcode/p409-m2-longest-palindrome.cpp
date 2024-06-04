#include <iostream>
#include<unordered_set>

using namespace std;

int longestPalindrome(string s) {
    unordered_set<int> odds;
    int length  =0;
    for(auto x:s){
        if( odds.find(x) != odds.end() ){
            odds.erase(x);
            length += 2;
        }

        else{
            odds.insert(x);
        }
    }

    if(!odds.empty()){
        length += 1;
    }

    return length;
}

int main(){
    string s = "HelloShubhGupta";
    cout<<longestPalindrome(s);

    return 0;
}
