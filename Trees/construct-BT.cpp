#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;

    TreeNode(int var){
        data = var;
        right = NULL;
        left = NULL;
    }
};
TreeNode* buildTreeHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMp ){
    if(preStart> preEnd || inStart> inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMp[root->data];
    int numLeft =  inRoot - inStart;
    root->left = buildTreeHelper(preorder, preStart+1, preStart-numLeft, inorder, inStart, inRoot-1, inMp);
    root->left = buildTreeHelper(preorder, preStart+1+numLeft, preEnd, inorder, inRoot+1, inEnd, inMp);
    return root;

}
TreeNode* buildTree(vector<int> &inorder, vector<int> &preorder){
    map<int, int> inMp;
    for(int i = 0; i < inorder.size(); i++){
        inMp[inorder[i]] = i;
        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMp);
    }
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(inorder, preorder);
    
    return 0;
}