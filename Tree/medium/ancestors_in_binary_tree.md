# Ancestors in Binary Tree

## Question 
https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a Binary Tree and an integer target. Find all the ancestors of the given target.

**Note:
The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.**

In case there are no ancestors available, return an empty list.
```
Examples:

Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1


Input:
        1
      /   \
     2     3
target = 1
Output: [ ]
Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(height of tree)
```

Constraints:<br>
1 ≤ no. of nodes ≤ 10<sup>3</sup><br>
1 ≤ data of node ≤ 10<sup>4</sup>



## Approach

We will use a pre-order traversal for this problem, will will go to each node and ask whether the data is equal to target or not, it it is equal we will return to the parent and push it into the ans, and push each parent to the ans.

1. Create an answer vector.
2. Start the pre-order traversal -
    - If the node is null we will return false, as there is no chance to find the target node ahead of the tree.
    - If the root node data is equal to target, we do not need to move further and return true.
    - Else check for left and right subtree, if the target is in left or right subtree we will get one of them as true.
    - If one of them is true push the root to answer vector and return true.
    - else return false.


## Code
```cpp
bool isAncestor(struct Node *root, int target, map<Node*, bool> &m, vector<int> &ans){
      if(root == nullptr)  return false;
      if(root->data == target)  return true;
      
      bool left = isAncestor(root->left, target, m,ans);
      bool right = isAncestor(root->right, target, m,ans);
      
      if(left || right){
          ans.push_back(root->data);
          return true;
      }
      
      return false;
  }
  
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        map<Node*, bool> m;
        
        vector<int> ans;
        
        isAncestor(root, target, m, ans);
        
        return ans;
        
    }
```