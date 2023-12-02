#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
} *head;

void create(int arr[], int n) {
    int i;
    struct Node *t, *last;

    head = new Node;
    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Iterative method to display linked list
void displayMethod1(struct Node *newNode) {
    while (newNode != nullptr) {
        cout << newNode->data << " ";
        newNode = newNode->next;
    }
}

// Recursive method to display linked list (first print, then call function again)
void displayMethod2(struct Node *newNode) {
    if (newNode->next != NULL) {
        cout << newNode->data << " ";
        displayMethod2(newNode->next);
    }
}

// Recursive method to display linked list (first call function, then print)
void displayMethod3(struct Node *newNode) {
    if (newNode->next != NULL) {
        displayMethod3(newNode->next);
        cout << newNode->data << " ";
    }
}

// Count the number of elements in the linked list
int countMethod1(struct Node *newNode) {
    int c = 0;
    while (newNode != nullptr) {
        c++;
        newNode = newNode->next;
    }
    return c;
}

// count number of element in linkedlist using recursive function
int countMethod2(struct Node *newNode){
    if(newNode == 0) return 0;
    return countMethod2(newNode->next)+1;
}

int main() {
    int a[] = {2, 6, 8, 4, 9, 4};
    create(a, 6);

    cout << "Display (Method-1) : ";
    displayMethod1(head);

    cout << endl << "Display (Method-2) : ";
    displayMethod2(head);

    cout << endl << "Display (Method-3) : ";
    displayMethod3(head);

    cout << endl << "Count (Method-1) : " << countMethod1(head);
    cout << endl << "Count (Method-2) : " << countMethod2(head);

    return 0;
}
