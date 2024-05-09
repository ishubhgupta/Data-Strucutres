#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int key){
    int l = 0;
    int r = nums.size()-1;
    while (l<r)
    {
        /* code */
        int mid = (l+r)/2;
        if(key == nums[mid]){
            return mid;
        }
        else if(key < nums[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    
    int mid = (l+r)/2;

}

int main(){
    vector<int> vec = {1, 3, 5, 6, 8, 9};
    cout<<searchInsert(vec, 7);
}