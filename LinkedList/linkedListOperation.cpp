#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
} *head;

void create(int arr[], int n) {
    int i;
    struct Node *t, *last;

    head = new Node;  // Corrected: Update the global head
    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++) {  // Corrected: Start the loop from 1
        t = new Node;  // Corrected: Remove Node * before t
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayMethod1(struct Node *newNode) {
    while (newNode != nullptr) {
        cout << newNode->data <<" ";
        newNode = newNode->next;
    }
}

// display linked list using recursion here(first we print then call function again)
void displayMethod2(struct Node *newNode){
    if(newNode->next != NULL){
        cout<<newNode->data<<" ";
        displayMethod2(newNode->next);
    }
}
// here me first call function then print
void displayMethod3(struct Node *newNode){
    if(newNode->next != NULL){
        displayMethod3(newNode->next);
        cout<<newNode->data<<" ";
        
    }
}

int main() {
    int a[] = {2, 6, 8, 4, 9, 4};
    create(a, 6);
    displayMethod1(head);
    cout<<endl<<"Display (Method-2) : ";displayMethod2(head);
    cout<<endl<<"Display (Method-3) : ";displayMethod3(head);

    return 0;
}
