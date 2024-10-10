#include <bits/stdc++.h>
using namespace std;

int main() {
    string content;
    cin>>content;
    char fl = content[0];
    if (fl >= 'A' && fl <='Z'){
        cout<<content;
    }
    else{
        content[0] = fl - 'a' + 'A';
        cout<<content;
    }
    return 0;
}