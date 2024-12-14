#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *prev;

    Node(int data, Node* next1, Node* prev1){
        val = data;
        next = next1;
        prev = prev1; 
    }
    Node(int data){
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

// del head of doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteKthElement(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    if (k == 0) {
        return deleteHead(head);
    }
    Node* temp = head;
    while (k > 0 && temp->next != nullptr) {
        temp = temp->next;
        k--;
    }
    if (k > 0) {
        return head;
    }
    if (temp->next) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    } else {
        temp->prev->next = nullptr;
    }
    delete temp;
    return head;
}

Node* reverseDLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp->next && !st.empty()){
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

}

Node* convertToDLL(vector<int> arr){
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4, 3, 11, 72, 21};
    Node *head = convertToDLL(arr);
    cout<<"Orignal: ";
    print(head);
    
    cout<<endl<<"deleted head: ";
    head = deleteHead(head);
    print(head);

    cout<<endl<<"deleted Tail: ";
    head = deleteTail(head);
    print(head);

    cout<<endl<<"delete kth element: ";
    head = deleteKthElement(head, 3);
    print(head);

    cout<<endl<<"Reversed DLL: ";
    head = reverseDLL(head);
    print(head);
    return 0;
}