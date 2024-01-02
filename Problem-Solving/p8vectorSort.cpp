// Problem Statement 8: Vector Sorting
// You are given a list of integers. Implement a program in C++ that sorts the elements in the list in ascending order using vectors.

// Input:

// The first line contains an integer 'n', the size of the list.
// The second line contains 'n' space-separated integers representing the elements of the list.
// Output:

// Print the sorted list in ascending order.
// Example:
// Input:

// Copy code
// 5
// 3 1 4 2 5
// Output:

// Copy code
// 1 2 3 4 5

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& vec1, int l, int mid, int r){
    int n1 = mid-l+1;
    int n2 = r-mid;

    vector<int> vecA, vecB;
    vecA.resize(n1);
    vecB.resize(n2);


    for(int i =0; i<n1;i++){
        vecA[i] = vec1[l+i];
    }
    for(int i =0; i<n2;i++){
        vecB[i] = vec1[mid+1+i];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(vecA[i]<=vecB[j]){
            vec1[k] = vecA[i];
            k++;i++;
        }
        else{
            vec1[k] = vecB[j];
            k++;j++;
        }
        
    }

    while(i<n1){
        vec1[k] = vecA[i]; 
        i++;k++;
    }
    while(j<n2){
        vec1[k] = vecB[j]; 
        j++;k++;
    }
    
}

void mergeSort(vector<int>& vec1, int l, int r){
    if(l<r){
        int mid = (l + r)/2;

        mergeSort(vec1,l,mid);
        mergeSort(vec1,mid+1,r);

        merge(vec1,l,mid,r);
    }
}

int main(){
    vector<int> vec1;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    mergeSort(vec1,0,vec1.size()-1);
    cout<<endl<<"Array Content (After sorting)- ";
    for(int x: vec1){
        cout<<x<<" ";
    }
    return 0;
}

