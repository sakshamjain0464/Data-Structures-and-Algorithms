# Find Zig-Zag Traversal

Question - https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/

Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

Example 1:

Input:
```
        1
      /   \
     2     3
    / \    /   \
   4   5 6   7
   ```
Output:

1 3 2 4 5 6 7

Example 2:

Input:
```
           7
        /     \
       9      7
     /  \        
    8   8  6     
   /  \
  10  9
  ``` 
Output:

7 7 9 8 8 6 9 10 

Your Task:

You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

Expected Time Complexity: O(n).

Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 105

## Approach
1. Use an boolean leftToRight variable.
2. Travese Level order.
3. Store Every level of the tree in an array.
4. If leftToRight is false, reverse the array.
5. Iterate over the array and push each element to answer vector.
6. Invert the variable leftToRight.

## Code
```cpp
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	
    	queue<Node*> q;
    	bool leftToRight = true;
    	q.push(root);
    	
    	while(!q.empty()){
    	    vector<int> level;
    	    int size = q.size();
    	    for(int i = 0; i<size; i++){
    	        Node* curr = q.front();
    	        q.pop();
    	        
    	        level.push_back(curr->data);
    	        
    	        if(curr->left) q.push(curr->left);
    	        if(curr->right) q.push(curr->right);
    	        
    	    }
    	    
    	    if(!leftToRight){
    	        reverse(level.begin(), level.end());
    	    }
    	    
    	    for(int i = 0; i<size; i++){
    	        ans.push_back(level[i]);
    	    }
    	    leftToRight = !leftToRight;
    	}
    	
    	return ans;
    }
```