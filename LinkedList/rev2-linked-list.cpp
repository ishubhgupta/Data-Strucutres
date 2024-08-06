#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

void insertBegin(ListNode*& head, int x) {
    ListNode* newnode = new ListNode(x);
    newnode->next = head;
    head = newnode;
}

void insertLast(ListNode*& head, int x){
    ListNode* newnode = new ListNode(x);
    if(!head){
        head = newnode;
        return;
    }
    ListNode* current = head;
    while(current->next){
        current = current->next;
    }
    current->next = newnode;
}

void delNode(ListNode* head, int x){
    if(!head) return;
    ListNode* current = head;
    
    while(current->next && current->next->val != x){
        current = current->next;
    }
    if(current->next){
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}


void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
    
int main() {
    ListNode* head = nullptr;

    insertBegin(head, 3);
    insertBegin(head, 2);
    insertBegin(head, 1);
    insertLast(head, 8);
    delNode(head, 2);

    printList(head);
    
    return 0;
}