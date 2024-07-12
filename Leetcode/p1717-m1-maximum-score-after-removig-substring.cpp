#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPresent(string s) {
        return s.find("ab") != string::npos || s.find("ba") != string::npos;
    }

    int maximumGain(string s, int x, int y) {
        int points = 0;
        while (isPresent(s)) {
            if (x > y) {
                size_t pos_ab = s.find("ab");
                size_t pos_ba = s.find("ba");
                if (pos_ab != string::npos) {
                    points += x;
                    s.erase(pos_ab, 2);
                } else if (pos_ba != string::npos) {
                    points += y;
                    s.erase(pos_ba, 2);
                }
            } else {
                size_t pos_ba = s.find("ba");
                size_t pos_ab = s.find("ab");
                if (pos_ba != string::npos) {
                    points += y;
                    s.erase(pos_ba, 2);
                } else if (pos_ab != string::npos) {
                    points += x;
                    s.erase(pos_ab, 2);
                }
            }
        }
        return points;
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
