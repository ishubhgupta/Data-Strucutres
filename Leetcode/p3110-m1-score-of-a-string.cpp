#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int scoreOfString(const string& s) {
    int n = s.size();
    int sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        sum += abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
    }

    return sum;
}

int main() {
    string testString = "Hello, World!";
    cout << "Score of the string: " << scoreOfString(testString) << endl;
    return 0;
}
