# Minimu Absolute Difference of Binary Tree

## Question
https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

Example 1:

Input:

Input tree

![input](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/712351/Web/Other/blobid0_1709057446.png)

Output:
10

Explanation:

There are no two nodes whose absolute difference is smaller than 10.
Example 2:

Input:

Input tree

![Image](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/712351/Web/Other/blobid2_1709058082.png)

Output:
20

Explanation:

There are no two nodes whose absolute difference is smaller than 20.

Your Task:

You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

Expected Time Complexity: O(n)

Expected Auxiliary Space: O(Height of tree)

Constraints:

2 <= n <= 105

1 <= Node->data <= 109

## Approach
Use inorder traversal and find difference between each node and give the difference which is minimum.

### Brute Force
1. Store the inorder traversal.
2. Iterate and find difference of adjacent elements(inorder[i] - inorder[i+1]).

This approach is not good because it will take more time by traversing the tree 2 times and taking the space O(n).

### Alternate Approach
1. Traverse inorder.
2. Keep track of previous node in inorder.
3. Find difference between current and previous nodes.

Note - To keep track of previous element in inorder, Assign previous after returning from the left call. 

## Code
```cpp
     Node* prev = nullptr;
    
    void traverse(Node* root, int &diff){
        if(root == nullptr) return;
        
        if(root->left){
            traverse(root->left, diff);
        }
        
        if(prev){
            diff = min(diff,abs(prev->data - root->data));
        }
        
        prev = root;
        
        if(root->right){
            traverse(root->right, diff);
        }
        
    }
    
    int absolute_diff(Node *root)
    {
        int diff = INT_MAX;
        traverse(root, diff);
        return diff;
    }
```