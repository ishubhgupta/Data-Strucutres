#include <iostream>
using namespace std;

struct matrix{
    int A[10][10];
    int n;    // dimension of matrix
};


void set(struct matrix *m, int i, int j, int x){
    m->A[i][j] = x;
    m->A[j][i]= x; 

}

int get(struct matrix *m, int i, int j){
        return m->A[i][j]; 

}

void display(struct matrix *m){

    for(int i= 0;i<m->n;i++){
        for(int j = 0; j < m->n; j++){
                cout<<m->A[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    struct matrix m;
    m.n = 4;

    set(&m, 0,0,1);
    set(&m, 0,1,2);
    set(&m, 0,2,3);
    set(&m, 0,3,4);
    set(&m, 1,1,5);
    set(&m, 1,2,6);
    set(&m, 1,3,7);
    set(&m, 2,2,8);
    set(&m, 2,3,9);
    set(&m, 3,3,10);

    display(&m);

    cout<<get(&m, 2, 3);
    return 0;
}