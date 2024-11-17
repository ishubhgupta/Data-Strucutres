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
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMp[root->data];
    int numLeft = inRoot - inStart;
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inMp);
    root->right = buildTreeHelper(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMp);
    return root;
}
TreeNode* buildTree(vector<int> &inorder, vector<int> &preorder){
    map<int, int> inMp;
    for(int i = 0; i < inorder.size(); i++){
        inMp[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMp);
}

int findCeil(TreeNode* root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }

        if(key > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}
int findfloor(TreeNode* root, int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }

        if(key > root->data){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(inorder, preorder);

    cout << "Ceil of 5: " << findCeil(root, 5) << endl; // Output should be 7
    cout << "Ceil of 10: " << findCeil(root, 10) << endl; // Output should be 15
    cout << "Ceil of 17: " << findCeil(root, 17) << endl; // Output should be 20

    return 0;
}