#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    vector<int> htable(128, 0);
    for (auto x : s) {
        htable[int(x)]++;
    }

    vector<pair<int, char>> pairs;
    int n = htable.size();
    for (int i = 0; i < n; i++) {
        if (htable[i] > 0) {
            pairs.push_back(make_pair(htable[i], char(i)));
        }
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, char>& left, const pair<int, char>& right) {
        return left.first > right.first;
    });

    string res;
    for (const auto& p : pairs) {
        res.append(p.first, p.second);
    }

    return res;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    string sorted = frequencySort(s);
    cout << "Sorted by frequency: " << sorted << endl;
    return 0;
}
