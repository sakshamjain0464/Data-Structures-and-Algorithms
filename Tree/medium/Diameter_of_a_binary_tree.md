# Calculate Diameter of a Binary Tree

Question - https://www.geeksforgeeks.org/problems/diameter-of-binary-tree

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 



Example 1:

Input:

       1
     /  \
    2    3
Output:  <br>
Example 2:

Input:
```
         10
        /   \
      20    30
    /   \ 
   40   60
   ```
Output: 4 <br>
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).<br>
Expected Auxiliary Space: O(Height of the Tree).

Constraints:<br>
1 <= Number of nodes <= 10000<br>
1 <= Data of a node <= 1000

## Approach
The diameter of a tree can be of one of these three
```
        -----     Diameter   -----
         /        |             \ 
        /         |              \
Left Subtree  Right Subtree    Sum of heights of both subrees     

```
- If any of these option is greater, that would be the diameter of the perticular subtree

## Code
```cpp
    pair<int, int> calculate(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> left = calculate(root->left);
        pair<int, int> right = calculate(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int, int> p;
        
        p.first = max(op1, max(op2, op3));
        p.second = max(left.second, right.second) + 1;
        
        return p;
    }
    
    int diameter(Node* root) {
        
        return calculate(root).first;
    }
```

Note - The pair is taken to optimize the code. we can create a height function and call it for op3 explicitly.