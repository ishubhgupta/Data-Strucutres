#include<iostream>
#include<queue>
#include<stack>
#include<vector>
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

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postOrder(struct Node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}

vector<vector<int>> bfs(struct Node *root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            Node *currentNode = q.front();
            q.pop();
            if (currentNode->left!=NULL) q.push(currentNode->left);
            if(currentNode->right!=NULL) q.push(currentNode->right);
            level.push_back(currentNode->data);
        }
        ans.push_back(level);
    }
    return ans;
}

void preorderIterative(struct Node* root){
    if(root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node *peek = st.top();
        st.pop();
        if(peek->right!= NULL) st.push(peek->right);
        if(peek->left!= NULL) st.push(peek->left);
        cout<<peek->data<<" ";
    }
}



void iterativeInorder(struct Node* root) {
    if (root == NULL) return;
    stack<Node*> st;
    Node* current = root;
    while (!st.empty() || current != NULL) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }
        Node *peek = st.top();
        st.pop();
        cout << peek->data << " ";
        current = peek->right;
    }
}


int main(){
    struct Node *root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Root data: " << root->data << endl;
    cout << "Left child data: " << root->left->data << endl;
    cout << "Right child data: " << root->right->data << endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postOrder(root);

    cout<<endl;
    vector<vector<int>> bfsResult = bfs(root);

    for (int i = 0; i < bfsResult.size(); i++) {
        for (int j = 0; j < bfsResult[i].size(); j++) {
            cout << bfsResult[i][j] << " ";
        }
    }
    cout<<endl;
    cout<<endl;
    preorderIterative(root);
    cout<<endl;
    iterativeInorder(root);
    return 0;
}