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

    printList(head);

    return 0;
}