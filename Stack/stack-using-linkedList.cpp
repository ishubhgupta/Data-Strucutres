#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Initialize top as a pointer to Node
Node *top = NULL;

// Push an element onto the stack
void push(int x) {
    Node *newnode = new Node();
    if (newnode == NULL) {
        cout << "Memory allocation failed" << endl;
    } else {
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }
}

// Pop an element from the stack
int pop(){
    Node *temp = top;

    if(top == NULL){
        return -1;
    }
    else{
        top=top->next;
        int x = temp->data;
        delete temp;
        return x;
    }

}

// Display elements of the stack
void display() {
    Node *current = top;
    if (current == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main() {
    push(5);
    push(7);
    push(8);
    push(9);
    push(6);

    cout << "Current stack: ";
    display();

    cout << "Popped element: " << pop() << endl;

    cout << "Stack after pop: ";
    display();

    return 0;
}
