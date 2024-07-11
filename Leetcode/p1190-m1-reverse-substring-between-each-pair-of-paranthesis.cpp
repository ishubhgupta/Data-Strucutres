#include <stack>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string reverseParentheses(string s) {
    stack<string> st;
    string res;
    for (char ch : s) {
        if (ch == '(') {
            st.push(res);
            res.clear();
        } else if (ch == ')') {
            reverse(res.begin(), res.end());
            if (!st.empty()) {
                res = st.top() + res;
                st.pop();
            }
        } else {
            res += ch;
        }
    }
    return res;
}

int main() {
    string s1 = "(abcd)";
    cout<<"Output for \"" << s1 << "\": "<<reverseParentheses(s1) << endl;

    string s2 = "(u(love)i)";
    cout << "Output for \"" << s2 << "\": " << reverseParentheses(s2) << endl;

    string s3 = "(ed(et(oc))el)";
    cout << "Output for \"" << s3 << "\": " << reverseParentheses(s3) << endl;

    return 0;
}
