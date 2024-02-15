## Find Boundary Traversal of Binary tree

Question - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. 

Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
```
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
```
   
Output: 1 2 4 8 9 6 7 3

Example 2:

Input:
```
            1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8
```

Output: 1 2 4 6 5 7 8

As you can see we have not taken the right subtree. 


Your Task:

This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 

Expected Auxiliary Space: O(Height of the Tree).

Constraints:

1 ≤ Number of nodes ≤ 105

1 ≤ Data of a node ≤ 105

## Approach
1. Push the root to the ans.
2. Print the left subtree.
    - if the root is null.
    - if the root is not a child.
    - push the data to ans
    - if left exists traverse left for left.
    - else traverse left for right.

3. Print the child nodes for left subtree
4. Print the child nodes of right subtree
5. Print the right nodes bottom up
    - if the root is null.
    - if the root is not a child.
    - if right exists traverse right for right.
    - else traverse right for left.
    - push the data to ans


## Code
```cpp
void traverseLeft(Node* root, vector<int> &ans){
        if(root){
            if(!root->left && !root->right){
                return;
            }
            ans.push_back(root->data);
            if(root->left){
                traverseLeft(root->left, ans);
            }
            else{
                traverseLeft(root->right, ans);
            }
        }
    }
    
    void traverseChild(Node* root, vector<int> &ans){
        if(root){
            if(root->left == nullptr && root->right == nullptr){
                ans.push_back(root->data);
                return;
            }
            
            else{
                traverseChild(root->left, ans);
                traverseChild(root->right, ans);
            }
        }
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(root){
            if(!root->left && !root->right){
                return;
            }
            if(root->right){
                traverseRight(root->right, ans);
            }
            else{
                traverseRight(root->left, ans);
            }
            ans.push_back(root->data);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        
        if(root == nullptr){
            return ans;
        }
        
        ans.push_back(root->data);
        
        traverseLeft(root->left, ans);
        
        traverseChild(root->left, ans);
        traverseChild(root->right, ans);
        
        traverseRight(root->right, ans);
        
        return ans;
    }


```