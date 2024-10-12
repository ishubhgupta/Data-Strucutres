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

// Function to check if the tree is balanced
bool isbalanced(struct Node* root){
    if(root == NULL) return true;

    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);

    if(abs(lh - rh) > 1) return false;

    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);
    return left && right;
}

// Function to calculate the height of the tree and update the diameter
int height(struct Node* root, int &diameter){
    if (root == NULL) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, rh + lh);
    return 1 + max(lh, rh);
}

// Function to return the diameter of the tree
int diameterOfBT(struct Node* root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

// Helper function to calculate the maximum path sum
int maxSumDown(struct Node* root, int &maxSum){
    if (root == NULL) return 0;
    int leftSum = max(0, maxSumDown(root->left, maxSum));
    int rightSum = max(0, maxSumDown(root->right, maxSum));
    maxSum = max(maxSum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}

// Function to calculate the maximum path sum of the tree
int maxPathSum(struct Node* root){
    int maxSum = INT_MIN;
    maxSumDown(root, maxSum);
    return maxSum;
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    cout << "Max Depth: " << maxdepth(root) << endl;
    cout << "Is Balanced: " << isbalanced(root) << endl;
    cout << "Diameter of Binary Tree: " << diameterOfBT(root) << endl;
    cout << "Max Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
