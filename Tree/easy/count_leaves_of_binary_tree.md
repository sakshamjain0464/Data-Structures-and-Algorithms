# Count Leaves of Binary Tree

Question - https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree

Given a Binary Tree of size N, You have to count leaves in it. For example, there are two leaves in following tree
```
        1
     /      \
   10      39
  /
5
```

Example 1:


Input:<br>

Given Tree is 

               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 

Output:
3
<br>
Explanation: 
Three leaves are 3 , 5 and 1.
 

Your Task:
You don't have to take input. Complete the function countLeaves() that takes root node of the given tree as parameter and returns the count of leaves in tree. The printing is done by the driver code.
 

Constraints:
1<= N <= 104

## Approach
1. Traverse each node.
2. If the left and right of that node is null, increment count by one.

## Code
Using Level order traversal
```cpp
    int countLeaves(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int count = 0;
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        // If leaf node
        if(!curr->left && !curr->right){
            count++;
        }
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    
    return count;
}
```
