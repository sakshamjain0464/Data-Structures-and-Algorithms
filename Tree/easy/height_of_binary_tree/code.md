# Find the height of binary tree

https://www.geeksforgeeks.org/problems/height-of-binary-tree

Given a binary tree, find its height.

Example 1:

Input:<br>
```
     1
    /  \
   2    3
```
Output: 2<br>
Example 2:

Input:<br>
```
  2
   \
    1
   /
 3
 ```
Output: 3 <br>  
Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 

Expected Time Complexity: O(N)<br>
Expected Auxiliary Space: O(N)

Constraints:<br>
1 <= Number of nodes <= 105<br>
1 <= Data of a node <= 109

## Approach
1. Traverse the left subtree and get its height
2. Traverse the right subtree and get its height.
3. Take maximum of both heights and add 1.
4. Return the final height.

## Code
```cpp
    int height(struct Node* node){
        if(node == nullptr){
            return 0;
        } 
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
```