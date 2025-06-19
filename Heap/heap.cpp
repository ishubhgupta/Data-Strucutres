#include <bits/stdc++.h>
using namespace std;


class maxHeap{
    private:
        int arr[100];
        int size;
    public:
        maxHeap(){
            arr[0] = -1;
            size = 0;
        }        void insert(int val){
            size++;
            int index = size;
            arr[index] = val;
            
            while(index > 1) {
                int parent = index/2;
                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }        
        
        void del(){
            if (size == 0) return;
            arr[1]= arr[size];
            size--;
            int index = 1;
            while(index<size){
                int left = 2*index;
                int right = 2*index+1;
                if(left<size && arr[index]<arr[left]){
                    swap(arr[index], arr[left]);
                    index = left;
                } 
                else if(right < size && arr[index]<arr[right]){
                    swap(arr[index], arr[right]);
                    index = right;
                } 
                else return;
            }
        }


        void print(){
            for(int i = 1; i<=size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};

void heapify(vector<int> arr, int size, int index){
    int largest = index;
    int left = index*2;
    int right = index*2+1;
    if(left<size && arr[largest]<arr[left]){
        largest = left;
    }
    if(right <size && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void heapSort(vector<int> inp){
    
    int n = inp.size()-1;
    int i = 0;
    while(n>0){
        for(int i = n/2; i>0; i--){
            heapify(inp, n, i+1);
        }
        cout<<inp[0]<<" ";
        i++;
    }
}
int main() {
    // maxHeap pq;
    // pq.insert(5);
    // pq.insert(20);
    // pq.insert(18);
    // pq.insert(3);
    // pq.insert(15);
    // pq.insert(2);
    // pq.insert(22);
    // pq.print();
    // pq.del();
    // pq.print();

    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0;i--){
        heapify(arr, n, i);
    } 

    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr);
    return 0;
}