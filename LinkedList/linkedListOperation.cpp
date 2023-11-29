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

void display(struct Node *newNode) {
    while (newNode != nullptr) {
        cout << newNode->data <<" ";
        newNode = newNode->next;
    }
}

int main() {
    int a[] = {2, 6, 8, 4, 9, 4};
    create(a, 6);
    display(head);

    return 0;  // Added: Return statement to indicate successful completion
}
