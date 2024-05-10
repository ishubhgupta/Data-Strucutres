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




// 1) Begin with the searchInsert function definition.
// 2) Inside the function:
    // a. Initialize left pointer l to 0 and right pointer r to nums.size() - 1.
    // b. Enter a while loop that continues as long as l is less than or equal to r.
    // c. Inside the loop:
        // i. Calculate the mid index as (l + r) / 2.
        // ii. Check if the key is equal to the element at the mid index. If so, return the mid index.
        // iii. If the key is less than the element at the mid index, update r to mid - 1.
        // iv. If the key is greater than the element at the mid index, update l to mid + 1.
    // d. If the loop exits without finding the key, return the left pointer l, which indicates the position to insert the key.
// 3) End of the searchInsert function.
// 4) In the main function:
    // a. Define a vector vec containing some sorted integers.
    // b. Call the searchInsert function with the vector vec and a key value.
    // c. Output the result of the function call.
// 5) End of the main function.