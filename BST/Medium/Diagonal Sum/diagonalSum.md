# Digonal Sum of BST

## Question
Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

For the following input tree, output should be 9, 19, 42.

9 is sum of 1, 3 and 5.

19 is sum of 2, 6, 4 and 7.

42 is sum of 9, 10, 11 and 12.

![image](https://media.geeksforgeeks.org/wp-content/uploads/diagonal-sum-in-a-tree.jpg)
```
Example 1:

Input:
         4
       /   \
      1     3
           /
          3
Output: 
7 4 
```
```
Example 2:

Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
Output: 
12 15 3 
```

Your Task:

You don't need to take input. Just complete the function diagonalSum() that takes root node of the tree as parameter and returns an array containing the diagonal sums for every diagonal present in the tree with slope -1.

Expected Time Complexity: O(nlogn).

Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 10^5
0 <= data of each node <= 10^4

## Approach
1. Use the level order traversal.
2. Take a queue and push the root into the queue.
3. Start traversing level order.
4. For each level take a sum variable and initialize it to zero.
5. pop the frot element of the queue and while it is not null,add its data to sum variable and if the left exist push the left into queue and assign the front poiter to the right of it.
6. After each level push the sum to ans vector.

## Code
```cpp
vector<int> diagonalSum(Node* root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int sum = 0;
            int size = q.size();
            for(int i = 0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                
                while(temp != nullptr){
                    sum += temp->data;
                    
                    if(temp->left){
                        q.push(temp->left);
                    }
                    
                    temp = temp->right;
                }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
```

