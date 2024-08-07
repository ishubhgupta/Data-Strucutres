#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string lessthanthousand(int num) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string sub_res;
        if (num >= 100) {
            sub_res += ones[num / 100] + " Hundred";
            num %= 100;
            if (num > 0) sub_res += " ";
        }
        if (num >= 20) {
            sub_res += tens[num / 10];
            num %= 10;
            if (num > 0) sub_res += " ";
        }
        if (num >= 10) {
            sub_res += teens[num - 10];
        } else if (num > 0) {
            sub_res += ones[num];
        }

        return sub_res;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> period = {"", "Thousand", "Million", "Billion", "Trillion"};
        string res;
        int place = 0;
        
        while (num > 0) {
            if (num % 1000 != 0) {
                string sub_result = lessthanthousand(num % 1000);
                if (!res.empty()) {
                    res = sub_result + " " + period[place] + " " + res;
                } else {
                    res = sub_result + " " + period[place];
                }
            }
            num /= 1000;
            place++;
        }

        while (res.back() == ' ') {
            res.pop_back();
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    int num;

    num = 123;
    cout << "Input: " << num << "\nOutput: " << sol.numberToWords(num) << endl;

    num = 12345;
    cout << "Input: " << num << "\nOutput: " << sol.numberToWords(num) << endl;

    num = 1234567;
    cout << "Input: " << num << "\nOutput: " << sol.numberToWords(num) << endl;

    num = 0;
    cout << "Input: " << num << "\nOutput: " << sol.numberToWords(num) << endl;

    return 0;
}
