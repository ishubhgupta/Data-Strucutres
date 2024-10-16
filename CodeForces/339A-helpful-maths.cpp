#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string digits;
    for (char c : s) {
        if (c != '+') {
            digits += c;
        }
    }

    sort(digits.begin(), digits.end());

    string result;
    for (int i = 0; i < digits.size(); i++) {
        if (i > 0) result += '+';
        result += digits[i];
    }

    cout << result << endl;

    return 0;
}
