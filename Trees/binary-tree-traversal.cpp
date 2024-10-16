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

void iterativePostorder2stack(struct Node* root){
    if (root == NULL) return;
    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty()){
        Node* peek = st1.top();
        st1.pop();
        st2.push(peek);

        if(peek->left != NULL) st1.push(peek->left);
        if(peek->right != NULL) st1.push(peek->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

vector<vector<int>> zigzag(struct Node* root){
    vector<vector<int>> res;
    if (root == NULL) return res;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i< size; i++){
            Node * crr = q.front();
            q.pop();

            int index = leftToRight ? i : size-1-i;
            level[index] = crr->data;

            if(crr->left != NULL) q.push(crr->left);
            if(crr->right != NULL) q.push(crr->right);

        }
        leftToRight = !leftToRight;
        res.push_back(level);
    }
    return res;

}

void traversal(struct Node* root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    if (root == NULL) return;

    stack<pair<Node*, int>> st;
    st.push(make_pair(root, 1));

    while(!st.empty()){
        int num = st.top().second;
        Node* curr = st.top().first;
        st.pop(); 

        if (num == 1) { 
            preorder.push_back(curr->data);
            st.push(make_pair(curr, 2));  
            if (curr->left != NULL) {
                st.push(make_pair(curr->left, 1));  
            }
        }
        else if (num == 2) { 
            inorder.push_back(curr->data);
            st.push(make_pair(curr, 3));  
            if (curr->right != NULL) {
                st.push(make_pair(curr->right, 1));
            }
        }
        else if (num == 3) { 
            postorder.push_back(curr->data);
        }
    }

    cout << "Preorder: ";
    for (auto x : preorder) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (auto x : inorder) {
        cout << x << " ";
    }
    cout << endl;

    cout << "PostOrder: ";
    for (auto x : postorder) {
        cout << x << " ";
    }
    cout << endl;
}
bool isLeaf(struct Node* root){
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}

void leftBoundary(struct Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left == NULL) curr = curr->right;
        else curr = curr->left;
    }
}

void leafNode(struct Node* root, vector<int> &res){
    if(root->left != NULL) leafNode(root->left, res);
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    } 
    if(root->right) leafNode(root->right, res);
}

void rightBoundary(struct Node* root, vector<int> &res){
    Node* curr = root->right;
    stack<int> st;
    while(curr){
        if(!isLeaf(curr)) st.push(curr->data);
        if(curr->right == NULL) curr = curr->left;
        else curr  = curr->right;
    }

    while(!st.empty()){
        int val = st.top();
        st.pop();
        res.push_back(val);
    }
}
void boundaryTraversal(struct Node* root){
    if (root == NULL) return;
    vector<int> res;
    if(!isLeaf(root)) res.push_back(root->data);
    leftBoundary(root, res);
    leafNode(root, res);
    rightBoundary(root, res);
    for(auto x: res){
        cout<<x<<" ";
    }
}

vector<vector<int>> verticalOrderTraversal(struct Node* root){
    vector<vector<int>> res;
    if(root == NULL) return res;
    int vr, hr;
    queue<pair<Node*, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        Node* crr = p.first;
        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(crr->data);
        if(crr->left) q.push({crr->left, {x-1, y+1}});
        if(crr->right) q.push({crr->right, {x+1, y+1}});
    }

    for (auto p : nodes) {
        vector<int> col;                
        for (auto q : p.second) {       
            col.insert(col.end(), q.second.begin(), q.second.end()); 
        }
        res.push_back(col);            
    }
    return res;
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
    cout<<endl;
    iterativePostorder2stack(root);
    cout<<endl;
    traversal(root);

    vector<vector<int>> zig = zigzag(root);
    cout<< "ZigZag traversal: ";
    for(int i = 0; i < zig.size();i++){
        for(int j = 0; j < zig[i].size(); j++){
            cout<<zig[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"Boundary Traversal: ";
    boundaryTraversal(root);

    vector<vector<int>> vlt = verticalOrderTraversal(root);
    cout<<endl;
    cout<< "Vertical Level traversal"<<endl;
    for(int i = 0; i < vlt.size();i++){
        cout<<"Level "<<i+1<<": ";
        for(int j = 0; j < vlt[i].size(); j++){
            cout<<vlt[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}