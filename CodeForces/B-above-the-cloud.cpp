#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        bool found = false;
        
        for (int len = 1; len <= n - 2 && !found; len++) {
            for (int st = 1; st <= n - len - 1 && !found; st++) {
                string b = s.substr(st, len);
                
                string a = s.substr(0, st);
                string c = s.substr(st + len);
                string ac = a + c;
                
                if (ac.find(b) != string::npos) {
                    found = true;
                }
            }
        }
        
        cout << (found ? "Yes" : "No") << "\n";
    }
    
    return 0;
}