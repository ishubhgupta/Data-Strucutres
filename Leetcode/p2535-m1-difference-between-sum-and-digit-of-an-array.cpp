#include <iostream>
#include <vector>

using namespace std;

int differenceOfSum(vector<int>& nums) {
    int elementSum =0;
    int digitSum = 0;
    for(auto x: nums){
        elementSum += x;
        int sum=0;
        while(x>0){
            int ld = x%10;
            sum += ld;
            x = x/10;
        }
        digitSum += sum;
    }
    return abs(elementSum - digitSum);
}

int main(){
    vector<int> vec1 = {1, 15, 6, 3};
    cout<<differenceOfSum(vec1);
}