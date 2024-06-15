#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void display(list<int> &lst){
    // list<int> :: iterator itr = lst.begin();
    for(auto itr = lst.begin(); itr!=lst.end();itr++){
        cout<<*itr<<" ";
    }

}

int main(){
    list<int> lst = {2, 5, 6, 7, 8, 8, 9, 4, 11};
    list<int> lst1(4);

    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_front(2);
    lst.remove(8);
    sort(lst.begin(), lst.end());
    display(lst);
    return 0;
}