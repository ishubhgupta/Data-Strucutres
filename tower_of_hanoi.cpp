#include <iostream>
using namespace std;

// void TOH(int n, char A, char B, char C){
//     if (n>0){
//         TOH(n-1, A, C, B);
//         cout<<"From "<<A<<" to "<<C<<endl;
//         TOH(n-1,B,A,C);
//     }
// }
// int main(){
//     TOH(5,'a','b','c');
// }

int f(int n)

{

static int i = 1;

if (n>=5)return n;

n = n+i;

i++;

return f(n);

}
int main(){
    cout<<f(1);
}