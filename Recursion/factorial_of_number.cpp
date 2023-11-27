#include <iostream>
using namespace std;

// recursion

// int factorial(int n){
//     if ( n == 0)
//         return 1;
//     else if (n == 1)
//         return 1;
//     else if (n>1)
//         return factorial(n-1) * n;
//     else
//         cout<<"not possible"<<endl;

// }
int iFact(int n){
    int fact =1;
    if (n == 0){
        return 1;
    }
    else{
        for(int i=1; i<=n; i++){
            fact *= i;
            
        }
        return fact;
    }

    
}

int main(){
    // cout<<factorial(10);
    cout<< iFact(5);
}