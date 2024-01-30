#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct linkedlist{
    Node *head = new Node();
    linkedlist(){
        head->next = nullptr;
    }

    void addElements(int arr[], int n){
        Node *last = new Node();
        head->data = arr[0];
        head->next = nullptr;
        last = head;


        for(int i = 0; i<n;i++){
            Node * currentNode = new Node();
            currentNode->data = arr[i];
            currentNode->next = NULL;
            last->next = currentNode;
            last = currentNode;
        }
    }

    void display(){
        Node *currentNode = new Node();
        cout<<"elements are : ";
        while(currentNode->next != nullptr){
            cout<<currentNode->data<<", ";
            currentNode = currentNode->next;
        }
    }
};

int main(){
    int arr[] = {2,3,4,5,6};
    linkedlist lst;

    lst.addElements(arr, 5);
    lst.display();
}
