# Top View of Binary Tree
Question - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
```
       1
    /     \
   2       3
  /  \    /   \
4    5  6   7
```

Top view will be: 4 2 1 3 7

Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 

For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
```
      1
   /    \
  2      3
```
Output: 2 1 3

Example 2:

Input:
```
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
```
Output: 40 20 10 30 100

Your Task:

Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(NlogN)

Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105

1 ≤ Node Data ≤ 105

## Approach
1. Use Vertical Traversal and print the first node corresponding to each level
2. Take a queue of int and Node type pair
3. Take a mapping of int -> int.
4. Push the root node to queue with level 0;
5. Iterate till queue is empty
    - Pop out the front of queue.
    - Extract the level and current node.
    - Find if something is present at that level if not put current node at that level
    - if left of the current code exists push pair of decrementing level and left node of current
    - if right of the current code exists push pair of incrementing level and right node of current.
7. Iterate the map.
    - Push the current node to ans
8. Return the answer vector.

## Code
```cpp
vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        
        queue<pair<int, Node*>> q;
        map<int, int> map;
        
        q.push(make_pair(0, root));
        
        while(!q.empty()){
            pair<int, Node*> front = q.front();
            q.pop();
            
            int level = front.first;
            Node* curr = front.second;
            
            auto i = map.find(level);
            
            if(i == map.end()){
                map[level] = curr->data;
            }
            
            if(curr->left) q.push(make_pair(level-1, curr->left));
            if(curr->right) q.push(make_pair(level+1, curr->right));
        }
        
        for(auto i : map){
            ans.push_back(i.second);
        }
        
        return ans;
    }
```
