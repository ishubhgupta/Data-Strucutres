#include <iostream>
using namespace std;

int main(){
    int arr1[] = {3,6,6,8,8,8,9,12,15,15,15,16,20,20};
    int l = 3;
    int h = 20;

    int H[h + 1]; // Adding 1 to the size to accommodate elements from 0 to h
    for(int i = 0; i <= h; i++){
        H[i] = 0;
    }

    for(int i = 0; i < h; i++){
        H[arr1[i]]++;
    }

    for(int i = 0; i <= h; i++){
        if(H[i] > 1) {
            cout << i << " appears " << H[i] << " times." << endl;
        }
    }
}
