# Find Left View of a binary tree
Question - https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.
```
          1
       /     \
     2        3
   /     \    / \
  4     5   6     7
   \
     8   
```

Example 1:

Input:
```
   1
 /  \
3    2
Output: 1 3
```
## Approach
Use level order traversal and track each level
Push the first element of each level into the ans array

## Code
```cpp
vector<int> leftView(Node *root)
{
    vector<int> ans;
    if(root == nullptr) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int count = q.size();
        
        for(int i = 0; i<count; i++){
            Node* curr = q.front();
            q.pop();
            
            if(i == 0) ans.push_back(curr->data);
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
    }
    
   return ans;
}
```
