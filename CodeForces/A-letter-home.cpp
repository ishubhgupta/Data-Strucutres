#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, s;
        cin >> n >> s;
        
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        
        int firstVal = *min_element(x.begin(), x.end());
        int lastVal = *max_element(x.begin(), x.end());
        

        int way1 = abs(s - firstVal) + abs(lastVal- firstVal);
        int way2 = abs(s - lastVal) + abs(lastVal- firstVal);
        
        int count = min(way1, way2);
        cout << count << endl;
    }
    return 0;
}