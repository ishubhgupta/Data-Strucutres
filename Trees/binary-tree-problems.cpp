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

void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode* target, int k){
    unordered_map<TreeNode*, TreeNode*> parent;
    markParent(root, parent);
    unordered_map<TreeNode*, bool> visited;

    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int currentLevel = 0;
    while(!q.empty()){
        int size = q.size();
        if (currentLevel++ == k) break;
        for( int i = 0; i< size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && ! visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent[node] && !visited[parent[node]]){
                q.push(parent[node]);
                visited[parent[node]];
            }
            
        }
    }

    vector<int> res;
    while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
    }
    return res;
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
    vector<int>result = distanceK(root, root->right, 1);
    for(auto x: result){
        cout<<x<<" ";
    }
}