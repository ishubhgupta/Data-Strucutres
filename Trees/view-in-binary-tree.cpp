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

vector<int> topView(struct TreeNode* root){
    vector<int> res;
    if(root == NULL) return res;
    map<int, int> nodes;
    queue<pair<int, TreeNode*>> q;

    q.push({0, root});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode *node = p.second;
        int line = p.first;

        if(nodes.find(line) == nodes.end()) nodes[line] = node->data;
        if(node->left) q.push({line-1, node->left});
        if(node->right) q.push({line+1, node->right});
    }

    for(auto x: nodes){
        res.push_back(x.second);
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

    vector<int> topv = topView(root);
    for(auto x: topv){
        cout<<x<<" ";
    }

    return 0;
}