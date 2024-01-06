#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec1.push_back(num);
    }
    int l = 0;
    int r = vec1.size() - 1;
    bool isPalindrome = true;
    while (l < r) {
        if (vec1[l] != vec1[r]) {
            isPalindrome = false;
            break;
        }
        l++;
        r--;
    }
    if (isPalindrome) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
