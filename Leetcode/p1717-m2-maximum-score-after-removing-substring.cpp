#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long sum = 0;
        
        if (x < y) {
            swap(x, y);
            for (char &ch : s) {
                if (ch == 'a') {
                    ch = 'b';
                } else if (ch == 'b') {
                    ch = 'a';
                }
            }
        }

        stack<char> stk;
        for (char ch : s) {
            if (!stk.empty() && stk.top() == 'a' && ch == 'b') {
                stk.pop();
                sum += x;
            } else {
                stk.push(ch);
            }
        }

        string remaining;
        while (!stk.empty()) {
            remaining += stk.top();
            stk.pop();
        }

        reverse(remaining.begin(), remaining.end());
        for (char ch : remaining) {
            if (!stk.empty() && stk.top() == 'b' && ch == 'a') {
                stk.pop();
                sum += y;
            } else {
                stk.push(ch);
            }
        }

        return sum;
    }
};

int main() {
    Solution solution;
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;

    int result = solution.maximumGain(s, x, y);
    cout << result << endl;

    return 0;
}
