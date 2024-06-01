#include <iostream>
using namespace std;

struct matrix{
    int A[10][10];
    int n;    // dimension of matrix
};


void set(struct matrix *m, int i, int j, int x){
    m->A[i][j] = x;
}

int get(struct matrix *m, int i, int j){
        return m->A[i][j]; 

}

void display(struct matrix *m){

    for(int i= 0;i<m->n;i++){
        for(int j = 0; j < m->n; j++){
            if(abs(i-j) <= 1){
                cout<<m->A[i][j]<<" ";
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
    set(&m, 0,1,2);
    set(&m, 1,0,3);
    set(&m, 1,1,4);
    set(&m, 1,2,4);
    set(&m, 2,1,5);
    set(&m, 2,2,6);
    set(&m, 2,3,7);
    set(&m, 3,2,8);
    set(&m, 3,3,9);
    set(&m, 3,4,10);

    display(&m);

    cout<<get(&m, 2, 3);
    return 0;
}