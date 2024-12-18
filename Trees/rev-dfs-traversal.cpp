#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(TreeNode* root, vector<int>& preorderTraversal){
    if(root == NULL) return;
    preorderTraversal.push_back(root->val);
    if(root->left) preorder(root->left, preorderTraversal);
    if(root->right) preorder(root->right, preorderTraversal);

}
void inorder(TreeNode* root, vector<int>& inorderTraversal){
    if(root == NULL) return;
    
    if(root->left) preorder(root->left, inorderTraversal);
    inorderTraversal.push_back(root->val);
    if(root->right) preorder(root->right, inorderTraversal);

}
void postorder(TreeNode* root, vector<int>& postorderTraversal){
    if(root == NULL) return;
    
    if(root->left) preorder(root->left, postorderTraversal);
    if(root->right) preorder(root->right, postorderTraversal);
    postorderTraversal.push_back(root->val);

}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);

    vector<int> preorderTraversal;
    preorder(root, preorderTraversal);
    cout<<"Preorder: ";
    for(auto x: preorderTraversal){
        cout<<x<<" ";
        
    }
    cout<<endl;

    vector<int> inorderTraversal;
    inorder(root, inorderTraversal);
    cout<<"Inorder: ";
    for(auto x: inorderTraversal){
        cout<<x<<" ";
        
    }
    cout<<endl;

    vector<int> postorderTraversal;
    postorder(root, postorderTraversal);
    cout<<"Postorder: ";
    for(auto x: postorderTraversal){
        cout<<x<<" ";
        
    }
    cout<<endl;
    return 0;
}