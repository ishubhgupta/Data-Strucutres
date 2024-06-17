#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool judgeSquareSum(int c) {
    long long l = 0;
    long long r = static_cast<int>(sqrt(c));

    while (l <= r) {
        long long sum = l * l + r * r;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            l++;
        } else {
            r--;
        }
    }

    return false;
}

int main(){
    cout<<judgeSquareSum(7);
    return 0;
}