#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;
    
    bool all_uppercase = true;
    for (char c : word) {
        if (!isupper(c)) {
            all_uppercase = false;
            break;
        }
    }
    bool first_lower_rest_upper = islower(word[0]);
    for (int i = 1; i < word.length(); ++i) {
        if (!isupper(word[i])) {
            first_lower_rest_upper = false;
            break;
        }
    }
    
    if (all_uppercase) {
        for (char &c : word) {
            c = tolower(c);
        }
    } else if (first_lower_rest_upper) {
        word[0] = toupper(word[0]);
        for (int i = 1; i < word.length(); ++i) {
            word[i] = tolower(word[i]);
        }
    }
    
    cout << word << endl;

    return 0;
}
