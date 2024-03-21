# Burnung Tree

## Question
https://www.geeksforgeeks.org/problems/burning-tree/1
 
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Example 1:
```
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
```
Example 2:
```
Input:       
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
```
Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.


Expected Time Complexity: O(N)

Expected Auxiliary Space: O(height of tree)

## Explaination
1. Firstly, we have to find the target node.
2. Now we will start burning the tree, on each second we will burn the parent, left and right node of each node which is burnt previously.

## Approach
1. We will create a child to parent mapping so that we can move from the child to its parent.(Using level order traversal) and also get the target node.
2. Now we will take a queue and a map in which we will mark whether the node is burnt or not.
3. Push the target to the queue and mark it as burnt.
4. Start level order traversal and at each level take a flag variable and start traversing the level using a for loop.
5. Pop the queue, push the left, right and parent element into the queue if they are not burnt and mark the flag as true.
6. After eah level if the flag is true increment the time by 1.

## Code
```cpp
map<Node*, Node*> createMapping(Node* root, Node* &targetNode, int target){
        // Function for creating child to parent mapping using level order traversal
        map<Node*, Node*> mapping;
        queue<Node*> q;
        q.push(root);
        mapping[root] = nullptr;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target) targetNode = front;  //Get the target node
            
            if(front->left){
                q.push(front->left);
                mapping[front->left] = front;
            }
            
            if(front->right){
                q.push(front->right);
                mapping[front->right] = front;
            }
        }
        
        return mapping;
    }
    
    int burnTree(Node* target, map<Node*, Node*> &nodeToParent){
        // Burning the tree using level order traversal
        // To check if the node is already burnt
        map<Node*, bool> burnt;
        queue<Node*> q;
        
        q.push(target);
        burnt[target] = true;
        int ans = 0;
        
        
        while(!q.empty()){
            int size = q.size();
            // Flag to check if any node is burnt at this level
            bool flag = false;
            
            for(int i = 0; i<size; i++){
                 Node* front = q.front();
                 q.pop();
                 
                 
                //  Push the parent of the left, right and parent of the current node into the queue if they are not burnt
                // And mark them as burnt
                 if(front->left && !burnt[front->left]){
                     q.push(front->left);
                     burnt[front->left] = true;
                     flag = true;
                 }
                 
                 if(front->right && !burnt[front->right]){
                     q.push(front->right);
                     burnt[front->right] = true;
                     flag = true;
                 }
                 
                 if(nodeToParent[front] && !burnt[nodeToParent[front]]){
                     q.push(nodeToParent[front]);
                     burnt[nodeToParent[front]] = true;
                     flag = true;
                 }
            }
            
            // if flag is true increment the time
            if(flag == true){
                ans++;
            }
        }
        
        
        return ans;
    }
    
  
    int minTime(Node* root, int target) 
    {
        Node* targetNode = nullptr;
        
        // Get the target node and create a child to parent mapping
        map<Node*, Node*> nodeToParent = createMapping(root, targetNode, target);
        
        // Burn the tree from target node
        int ans = burnTree(targetNode,nodeToParent);
        
        return ans;
    }
```
