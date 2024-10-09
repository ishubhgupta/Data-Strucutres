#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0;i<n;i++){
        cin>>words[i];
    }

    vector<string> res;
    for(auto word: words){
        int size = word.size();
        if(size>10){
            string w = word[0] + to_string(size-2) + word[size-1];
            res.push_back(w);
        }
        else{
            res.push_back(word);
        }
    }
    for(auto abbr: res){
        cout<<abbr<<endl;
    }
    
    return 0;
}