#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec1, vec2;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int num;
        cin>>num;
        vec1.push_back(num);
    }

    for(int i = 0;i<n-1;i++){
        int sum = 0;
        sum = sum + vec1[i] + vec1[i+1];
        vec2.push_back(sum);
    }

    for(int x:vec2){
        cout<<x<<" ";
    }
}
