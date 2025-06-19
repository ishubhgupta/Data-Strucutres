#include <bits/stdc++.h>
using namespace std;


struct Stack{
    int arr[10];
    int top;

    Stack(){
        top = -1;
    }
};

void push(Stack &st, int val){
    if(st.top>9) return;
    st.top = st.top + 1;
    st.arr[st.top] = val; 
}



int main() {
    
    return 0;
}