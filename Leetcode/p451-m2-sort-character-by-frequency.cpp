#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freq_map;
    for(auto c :s){
        freq_map[c]++;
    }

    sort(s.begin(), s.end(), [&](char a, char b){
        if(freq_map[a]!=freq_map[b]){
            return freq_map[a]>freq_map[b];
        }
        return a<b;
    });

    return s;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string sorted = frequencySort(s);
    cout << "Sorted by frequency: " << sorted << endl;
    return 0;
}
