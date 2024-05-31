#include <iostream>
using namespace std;

struct matrix{
    int A[10];
    int n;    // dimension of matrix
};


void set(struct matrix *m, int i, int j, int x){
    if(i == j){
        m->A[i] = x; 
    }
}

int get(struct matrix *m, int i, int j){
    if(i == j){
        return m->A[i]; 
    }
    else{
        return 0;
    }
}

void display(struct matrix *m){

    for(int i= 0;i<m->n;i++){
        for(int j = 0; j < m->n; j++){
            if(i == j){
                cout<<m->A[i]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}



int main(){
    struct matrix m;
    m.n = 4;

    set(&m, 0,0,1);
    set(&m, 1,1,2);
    set(&m, 2,2,3);
    set(&m, 3,3,4);
    display(&m);

    cout<<get(&m, 3, 4);
    return 0;
}