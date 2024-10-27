#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;

    TreeNode(int var){
        val = var;
        right = NULL;
        left = NULL;
    }
};

bool rootToNodePath(struct TreeNode* root, vector<int> &path, int target){
    if(root == NULL) return false;
    path.push_back(root->val);

    if(root->val == target) return true;

    
    if( rootToNodePath(root->left, path, target) ||  rootToNodePath(root->right, path, target)){
        return true;
    }
    path.pop_back();
    return false;
}

int lowestCommonAncestor(vector<int> path1, vector<int> path2){
    int n = min(path1.size(), path2.size());
    for(int i = 0;i<n;i++){
        if(path1[i] != path2[i]){
            return path1[i-1];
        }
    }
}

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0; 

    int maxWidth = 0;
    queue<pair<TreeNode*, unsigned long long>> q; 
    q.push({root, 0});

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long minIndex = q.front().second; 
        unsigned long long first, last;

        for (int i = 0; i < levelSize; ++i) {
            unsigned long long currIndex = q.front().second - minIndex;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0) first = currIndex;
            if (i == levelSize - 1) last = currIndex;

            if (node->left) q.push({node->left, 2 * currIndex});
            if (node->right) q.push({node->right, 2 * currIndex + 1});
        }
        
        maxWidth = max(maxWidth, int(last - first + 1));
    }

    return maxWidth;
}

void childrenSumProperty(TreeNode* root){
    if (root == NULL) return;
    int child = 0;
    if(root->left) {
        child += root->left->val;
    }
    if(root->right){
        child += root->right->val;
    }
    if(child<root->val){
        if(root->left) root->left->val = child;
        else if(root->right) root->right->val = child;
    }
    childrenSumProperty(root->left);
    childrenSumProperty(root->right);

    int total = 0;
    if(root->left) total = root->left->val;
    if(root->right) total = root->right->val;
    if(root-> val || root->right) root->val = total;    
}

int main() {
    struct TreeNode *root = new TreeNode(1);
    root->left =new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> path1, path2;

    rootToNodePath(root, path1, 4);
    rootToNodePath(root, path2, 5);
    cout<<lowestCommonAncestor(path1, path2);
    cout<<endl;
    return 0;
}