// Given a number n, for each integer in the range from 1 to n inclusive, print one value per line as follows:

// • If iis a multiple of both 3and 5, print FizzBuzz.

// • If iis a multiple of 3(but not 5), print Fizz.

// • If iis a multiple of 5(but not 3), print Buzz.

// • If iis not a multiple of 30r 5, print the value of i.

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



void printFizzBuzz(){
    cout<<"FizzBuzz"<<endl;
}
void fizzBuzz(int n) {
    int i =1;
    while(i<n){
        if(i%3 == 0 && i%5 == 0){
            printFizzBuzz();    
        }
        else if(i%3==0){
            cout<<"Fizz"<<endl;
        }
        else if(i%5==0){
            cout<<"Buzz"<<endl;
        }
        else{
            cout<<i<<endl;
        }
        i++;
    }

}
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    fizzBuzz(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
