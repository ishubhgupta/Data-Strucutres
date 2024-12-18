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

vector<vector<int>> bfs(TreeNode* root, vector<vector<int>>& pathBFS){
    if(root == NULL) return pathBFS;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for(int i = 0; i< size; i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        pathBFS.push_back(level);
    }
    return pathBFS;
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


    vector<vector<int>> pathBFS; 
    bfs(root, pathBFS);
    
    cout << "BFS traversal: \n";
    for(int i = 0; i < pathBFS.size(); i++){
        cout << "Level " << i << ": ";
        for(int val : pathBFS[i]){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}