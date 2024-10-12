#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *right;
    struct Node *left;

    Node(int var){
        data = var;
        right = NULL;
        left = NULL;
    }
};

int maxdepth(struct Node* root){
    if (root == NULL) return 0;

    int ls = maxdepth(root->left);
    int rs = maxdepth(root->right);
    return 1 + max(rs, ls);
}

// balanced binary tree
bool isbalanced(struct Node* root){
    if(root == NULL) return true;
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);

    if(abs(lh-rh)>1) return false;
    isbalanced(root->left);
    isbalanced(root->right);
    if(!left || !right) return false;
    return true;
}

int height(struct Node* root, int &diameter){
    if (root == NULL) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, rh+lh);
    return 1 + max(lh, rh);
}

int diameterOfBT(struct Node* root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    struct Node *root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(9);

    cout<<maxdepth(root);
    cout<<endl;
    cout<<isbalanced(root);
    cout<<endl;
    cout<<diameterOfBT(root);
    return 0;
}