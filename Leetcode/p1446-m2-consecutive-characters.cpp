#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int pow = 1;
        for(int i = 0;i<n;i++){
            int tempcount = 1;
            while(i + 1 < n && s[i] == s[i + 1]){
                tempcount++;
                i++;
            }
            pow = max(pow, tempcount);
        }
        return pow;
    }

};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "leetcode";
    cout << "Max power of \"" << s1 << "\" is " << solution.maxPower(s1) << endl;

    // Test case 2
    string s2 = "abbcccddddeeeeedcba";
    cout << "Max power of \"" << s2 << "\" is " << solution.maxPower(s2) << endl;

    // Test case 3
    string s3 = "triplepillooooow";
    cout << "Max power of \"" << s3 << "\" is " << solution.maxPower(s3) << endl;

    // Test case 4
    string s4 = "hooraaaaaaaaaaay";
    cout << "Max power of \"" << s4 << "\" is " << solution.maxPower(s4) << endl;

    // Test case 5
    string s5 = "tourist";
    cout << "Max power of \"" << s5 << "\" is " << solution.maxPower(s5) << endl;

    return 0;
}
// this sol is not best optimized method 1 is better