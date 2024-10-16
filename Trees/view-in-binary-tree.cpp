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


void buttomView(struct TreeNode* root){
    if(root == NULL) return;

    queue<pair<TreeNode*, int>> q;
    map<int, int> mpp;

    q.push(make_pair(root, 0));
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int line = p.second;

        mpp[line] = node->data;
        if(node->left) q.push(make_pair(node->left, line-1));
        if(node->right) q.push(make_pair(node->right, line+1));
    }

    for(auto x: mpp){
        cout<<x.second<<" ";
    }
}

void rightView(struct TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return;
    if(res.size() == level){
        res.push_back(root->data);
    }
    if(root->right) rightView(root->right, level+ 1, res);
    if(root->left) rightView(root->left, level+ 1, res);

}
void leftView(struct TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return;
    if(res.size() == level){
        res.push_back(root->data);
    }
    if(root->left) leftView(root->left, level+ 1, res);
    if(root->right) leftView(root->right, level+ 1, res);
    
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
    cout<<endl;
    buttomView(root);

    vector<int> rightV;
    rightView(root,0, rightV);
    cout<<endl<<"Right View: ";
    for(auto x : rightV){
        cout<<x<< " ";
    }

    vector<int> leftV;
    leftView(root,0, leftV);
    cout<<endl<<"Left View: ";
    for(auto x : leftV){
        cout<<x<< " ";
    }
    return 0;
}