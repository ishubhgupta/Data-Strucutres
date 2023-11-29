#include <iostream>
using namespace std;
// sorted Array

void method1(){
    int arr1[] = {3, 6, 6, 8, 8, 8, 9, 12, 15, 15, 15, 16, 20, 20};
    int n = 14;
    int lastDuplicate = 0;
    for(int i=0;i<n-1;i++){
        if(arr1[i]==arr1[i+1]){
            int j = i+1;
            while(arr1[j]==arr1[i]){
                j++;
            }
            cout<<arr1[i]<<" is repeating "<<j-i<<" times."<<endl;
        }
    }
}

void hashingMethod() {
    int arr1[] = {3, 6, 6, 8, 8, 8, 9, 12, 15, 15, 15, 16, 20, 20};
    int h = sizeof(arr1) / sizeof(arr1[0]);

    int H[h];

    for (int i = 0; i < h; i++) {
        H[i] = 0;
    }

    for (int i = 0; i < h; i++) {  
        H[arr1[i]]++;
    }

    for (int i = 0; i <= h; i++) {
        if(H[i]>1){
            cout << i << " appears " << H[i] << " times." << endl;
        }
        
    }
}

int main() {
    // hashingMethod();
    method1();
    return 0;
}
