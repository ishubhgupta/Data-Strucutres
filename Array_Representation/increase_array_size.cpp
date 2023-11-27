#include <iostream>
using namespace std;

int main(){
    int *p = new int[5];
    p[0] = 1;p[1] = 2; p[2] = 5; p[3] = 4;
    int *q = new int[10];

    for(int i = 0; i<=4; i++){
        q[i] = p[i];
    }
    delete []p;
    p=q;
    q = NULL;

    for(int i =0; i<=9; i++){
        cout<<p[i]<<" ";
    }

}