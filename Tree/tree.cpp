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

int main(){
    Node* root = buildTree();
    cout<<endl;
    levelOrder(root);
    return 0;
}