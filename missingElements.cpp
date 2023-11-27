#include <iostream>
using namespace std;

void method1(){
    int arr1[] = {1,2,3,4,5,6,8,9,10,11,12};
    int n = 12;
    n = (n+1)*n/2;
    int sum = 0;
    for(int i=0; i<11;i++ ){
        sum += arr1[i]; 
    }

    int missingNum = n-sum;
    cout<<"Missing Number : "<<missingNum<<endl;

}

void method2(){
    int arr2[] = {6,7,8,9,10,11,13,14,15,16,17};
    int l =6;
    int h = 17;
    int n = 11;
    int diff = l-0;

    for(int i =0; i<n; i++){
        if(arr2[i] - i != diff){
            cout<<"Missing Number : "<<i+diff<<endl;
            break;
        }
    }
}

void method3(){
    int arr3[] = {6,7,8,9,11,12,15,16,17,18,19};
    int l = 6;
    int h = 19;
    int n = 11;
    int diff = l-0;

    for(int i =0; i<n;i++){
        while(diff< arr3[i] - i){
            cout<<"Missing Number : "<<i+diff<<endl;
            diff++;
        }
    }
}

void method4(){
    int arr4[] = {3,7,4,9,12,6,1,11,2,10};
    int l=1;
    int h = 12;
    int n = 10;
    int H[h];
    for(int i = 0; i<h;i++){
        H[i] = 0;
    }

    for(int i=0;i<n;i++){
        H[arr4[i]]++;
    }

    for(int i=l;i<=h;i++){
        if(H[i] == 0){
            cout<<"Missing Number : "<<i<<endl;
        }
    }
}

int main(){
    method4();
}

