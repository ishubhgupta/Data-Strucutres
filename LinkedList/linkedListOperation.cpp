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
// array
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

// sum of elements using itrative approch in linked list
int sumOfElementMethod1(struct Node *newNode){
    int sum = 0;
    while(newNode!=NULL){
        sum += newNode->data;
        newNode = newNode->next;
    }
    return sum;
}
// sum of element using recursive approch in linked list
int sumOfElementMethod2(struct Node *newNode) {
    if (newNode == nullptr) return 0; 
    return newNode->data + sumOfElementMethod2(newNode->next);
}

// maximum of element in linked list using itretive method
int maxOfElementMethod1(struct Node *newNode){
    int max = newNode->data;
    while(newNode!=NULL){
        if(newNode->data > max){
            max = newNode->data;
        }
        newNode = newNode->next;
    }
    return max;
}

// maximum of element in linked list using recursive function
int maxOfElementMethod2(struct Node *newNode){
    int x = 0;
    if(newNode == 0) return 0;
    else{
        x = maxOfElementMethod2(newNode->next);
        if(newNode->data < x){
            return x;
        }
        else
            return newNode->data;
    }
}
// this function perform linear seach in linked list using iterative method
struct Node * SearchM1(struct Node *p, int key){
    while(p->next !=0){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// this function performlinear search in linked list using recursive method

struct Node * SearchM2(struct Node* p, int key){
    if(p == NULL){
        return NULL;
    }
    if(p->data == key){
        return p;
    }
    return SearchM2(p->next, key);
}

//  this function performed improved linear search using move to head method

struct Node* SearchM3(struct Node *p, int key){
    Node *q = NULL;
    while(p != NULL){
        if (key == p->data){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }    
        q = p;
        p = p->next;
    }
    return NULL; 
}

int main() {
    struct Node *temp;
    int a[] = {2, 6, 8, 4, 9, 7};
    create(a, 6);

    temp = SearchM3(head, 7);
    if(temp){
        cout<<"Key "<<temp->data<<" found!!"<<endl;
    }
    else{
        cout<<"Key Not found!!";
    }

    displayMethod1(head);

    // cout << "Display (Method-1) : ";
    // displayMethod1(head);

    // cout << endl << "Display (Method-2) : ";
    // displayMethod2(head);

    // cout << endl << "Display (Method-3) : ";
    // displayMethod3(head);

    // cout << endl << "Count (Method-1) : " << countMethod1(head);
    // cout << endl << "Count (Method-2) : " << countMethod2(head);
    // cout << endl << "Sum of Element (Method-1) : " << sumOfElementMethod1(head);
    // cout << endl << "Sum of Element (Method-2) : " << sumOfElementMethod2(head);
    // cout << endl << "Max of Element (Method-1) : " << maxOfElementMethod1(head);
    // cout << endl << "Max of Element (Method-2) : " << maxOfElementMethod2(head);

    return 0;
}
