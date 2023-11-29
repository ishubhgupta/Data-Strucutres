#include <iostream>
using namespace std;

struct array{
    int *a;
    int size;
    int length;
};

void display(struct array arr){
    cout<<"element are : ";
    for(int i =0; i<arr.length ; i++){
        cout<<arr.a[i]<<" ";
    }
}

int main(){
    array arr;

    // initialization of an array
    cout<<"enter size of array : ";
    cin>>arr.size;
    arr.a = new int[arr.size]; //crateing array inside heap
    arr.length = 0;

    int n;
    cout<<"total element in array : ";
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<"enter element "<<i+1<<" : ";
        cin>>arr.a[i];
    }
    arr.length =n;

    display(arr);
}