#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    int case1 = a + b + c;
    int case2 = a + b * c;
    int case3 = (a + b) * c;
    int case4 = a * b * c;
    int case5 = a * (b + c);
    cout<<max({case1, case2, case3, case4, case5});
    return 0;
}