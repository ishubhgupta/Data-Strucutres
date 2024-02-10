#include<iostream>
using namespace std;

struct array{
    int a[20];
    int size, length;
};

void swap2(int a, int b){
    a = a-b;
    b = b+a;
    a = b-a;
    cout<<a<<" and "<<b<<endl;
}

void display(const struct array &arr1){
    for(int i =0;i<arr1.length;i++){
        cout<<arr1.a[i]<<" ";
    }
}

void append(struct array &arr1, int val){
    if(arr1.length < arr1.size){
        arr1.a[arr1.length++] = val;
    }
}

void insert(struct array &arr1, int pos, int val){
    if(arr1.length<arr1.size){
        for(int i = arr1.length; i>pos; i--){
            arr1.a[i] = arr1.a[i-1];
        }
        arr1.a[pos] = val;
        arr1.length++;
    }
}
int get(struct array &arr1, int indx){
    return arr1.a[indx-1];
}

void reverseM1(struct array &arr1){
    struct array arr2;
    arr2.size = arr1.size;
    arr2.length = arr1.length;

    for(int i = arr1.length - 1, j = 0; i >= 0; i--, j++){
        arr2.a[j] = arr1.a[i];
    }
    
    for(int i = 0; i < arr2.length; i++){
        cout << arr2.a[i] << " ";
    }
}

int main(){
    cout<<"swap - "; swap2(25, 50);
    struct array arr1 = {{2, 3, 4, 5, 6, 7}, 20, 6};
    display(arr1);
    cout<<endl;
    append(arr1, 8);
    display(arr1);cout<<endl;
    cout<<get(arr1, 4)<<endl;
    reverseM1(arr1);

}