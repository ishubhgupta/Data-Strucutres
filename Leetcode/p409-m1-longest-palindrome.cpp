#include <iostream>
using namespace std;

int longestPalindrome(string s) {
    int htable[128] = {0};

    for(auto x: s){
        htable[static_cast<int>(x)]++;
    }

    int length = 0;
    bool odd_found = false;

    for(int i = 0; i < 128; i++){
        if (htable[i] % 2 == 0) {
            length += htable[i];
        } else {
            length += htable[i] - 1;
            odd_found = true;
        }
    }

    if (odd_found) {
        length += 1;
    }

    return length;
}

int main(){
    string s = "HelloShubhGupta";
    cout<<longestPalindrome(s);

    return 0;
}

// this problem can hae more optimized solution too