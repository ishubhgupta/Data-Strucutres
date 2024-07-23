#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


auto greet = [](){
    cout<<"Hello World!!"<<endl;
};

auto add = [](int a, int b){
    cout<<a<<" + "<< b << " = " <<a+b<<endl;
};

auto divide = [](int a, int b) -> double{
    cout<<a<<" / "<< b << " = " <<static_cast<double>(a)/b<<endl;
};

void stlalgo1(){
    vector<int> vec1 = {2, 3, 5, 6, 8, 7, 4};
    for_each(vec1.begin(), vec1.end(), [](int a){
        cout<<a<< " ";
    });
    cout<<endl;
}

void customOperator(){
    vector<int> vec2 = {2, 3, 5, 6, 8, 7, 4};
    sort(vec2.begin(), vec2.end(), [](int a, int b){
        return b<a;
    });
    cout<<"Sorted in descending Order: ";
    for_each(vec2.begin(), vec2.end(), [](int a){
        cout<<a<<" ";
    });
    cout<<endl;
}


int main(){
    greet();
    add(3, 4);

    int x = 10;

    auto printx = [x]() mutable { // either u can use this mutable keyword or use & before x to use it as address, other wise x will be read only variable and cannot be modified...
        cout<<"X is: "<<x<<endl;
        x +=10;
        cout<<"X is: "<<x<<endl;

    };

    printx();

    divide(16, 5);

    stlalgo1();

    customOperator();
    return 0;
}