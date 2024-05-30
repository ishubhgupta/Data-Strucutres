#include <iostream>
#include <vector>

using namespace std;

    int addDigits(int num) {
        while(num>9){
            int sum = 0;
            while(num>0){
                int ld = num%10;
                sum += ld;
                num = num/10;  
            }
            num = sum;
        }
        return num;
    }

int main(){
    cout<<addDigits(1001);
}