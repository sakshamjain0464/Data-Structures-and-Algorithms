# is Binary Tree a MaxHeap

## Question
https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

Given a binary tree. The task is to check whether the given tree follows the max heap property or not.

**Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.**

```
Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.
```
```
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
```

Your Task:<br>
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N) <br>
Expected Space Complexity: O(N)

Constraints: <br>
1 ≤ Number of nodes ≤ 100 <br>
1 ≤ Data of a node ≤ 1000  <br>

## Approach
1. Check if the tree is CBT
2. Check if tree is MaxHeap
3. If it is both return true else return false

## Checking CBT
We need to check the if the tree is filled from left, hence it will not contain any null pointer in between of nodes.

To check that we will take index starting from 0 and call for keft and right index(as we are checking heap the left is 2xi + 1 and right is 2xi+2).

If the index goes beyond the number of nodes, we can say that it is not a CBT.

### pseudo-code
```
    if(root is null){
        return true         //because if index is higher than  no. of nodes it should always be null
    }

    //If something is present

    if(index >= count) return false

    left = call for left
    right = call for right

    return left && right
```

## Checking MaxHeap
We can traverse the tree inorder, if the left and right subtree is MaxHeap and the left and right nodes are less than the root node then it is a MaxHeap

### pseudo code
```
      if(root is null){
        return true              //because leaf node is always a Heap

        if(root->left && root->left->data > root->data){
            return false;
        }

        if(root->right && root->right->data > root->data){
            return false;
        }

        //Check for left and right subtrees
        left = call for left
        right = call for right

        return left&&right
      }
```

## Code
```cpp
int countNodes(struct Node* root){
      if(root == nullptr){
          return 0;
      }
      
      return 1 + countNodes(root->left) + countNodes(root->right);
  }
  
  bool isCBT(struct Node* root, int index, int count){
      if(root == nullptr){
          return true;
      }
      
      if(index >= count){
          return false;
      }
      
      else{
          bool left = isCBT(root->left, 2*index + 1, count);
            bool right = isCBT(root->right, 2*index + 2, count);
      
        return left&&right;
      }
  }
  
  bool isMaxHeap(struct Node* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        
        }
        
        if(root->left){
                if(root->left->data > root->data){
                    return false;
                }
            }
            
            if(root->right){
                if(root->right->data > root->data){
                    return false;
                }
            }
        
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        
        return left&&right;
    }
  
    bool isHeap(struct Node* root) {
        int count = countNodes(root);
        
        return isCBT(root, 0, count) && isMaxHeap(root);
    }
```