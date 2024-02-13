#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree() {
    cout<<"Enter Data : ";
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    
    Node* root = new Node(d);
    cout<<"Insert in left of "<<d<<" : "<<endl;
    root->left = buildTree();
    cout<<"Insert in right of "<<d<<" : "<<endl;
    root->right = buildTree();
    
    return root;
}

void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == nullptr){
            if(!q.empty()){
                q.push(nullptr);
            }
            cout<<endl;
        }
        else{
            cout<<curr->data<<" ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

void levelOrder2(Node* root){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        int count = q.size();

        for(int i=0; i<count; i++){
            Node* curr = q.front();
            q.pop();

            cout<<curr->data<<" ";

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<<endl;
    }
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr){
        return;
    }

    postorder(root->right);
    postorder(root->left);

    cout<<root->data<<" ";
}

int main(){
    Node* root = buildTree();
    cout<<endl;
    levelOrder2(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}