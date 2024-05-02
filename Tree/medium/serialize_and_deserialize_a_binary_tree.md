# Serialize and Deserialize a Binary Tree

## Question
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.<br>
deSerialize() : deserializes the array to the tree and returns the root of the tree.

Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).
```
Example 1:

Input:
      1
    /   \
   2     3
Output: 
2 1 3
```

```
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 
40 20 60 10 30
```

Your Task:<br>
The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(Number of nodes).<br>
Expected Auxiliary Space: O(Number of nodes).

Constraints:<br>
1 <= Number of nodes <= 10<sup>4</sup><br>
1 <= Data of a node <= 10<sup>9</sup>

## Approach
**There are two steps- Serialization and De-serialization**
### Serialze:
1. Use Level-Order Traversal to store the elements of the array.
2. If there is null put -1 into the array

### De-serialze:
1. Pop out the first element of the array and Create a node from the element and push into the queue.
2. Using Level-Order:
    - Pop out the current node from the queue.
    - Pop out the front element from the array, if it is -1 assign null to the left of the current node.
    - If it is a valid element, create a node out of it and assign the left to the new node.
    - Push the left to the queue.
    - Same for the right of that node.
3. The tree is created, return the root node.

## Code
```cpp
//Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;        // Create a vector
        queue<Node*> q;         // Create a queue
        q.push(root);
        
        while(!q.empty()){
            Node* s = q.front();     
            q.pop();
            
            if(s == nullptr){                 
                ans.push_back(-1);         // If the element is null push -1 to indicate that there is no node
                continue;
            }
            ans.push_back(s->data)       // Push the data into vector
            
            q.push(s->left);      // Push the left
            q.push(s->right);     // Push the right
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       Node* root = new Node(A[0]);            // Create a node from the first element of the vector
       A.erase(A.begin());                    // Remove the first element
       
       queue<Node*> q; 
       q.push(root);                          // Use a queue for Level-order traversal                      
       
       while(!A.empty() && !q.empty()){
           Node* temp = q.front();              // Pop the first element of the queue
           q.pop(); 
           
        //   Pop out the vector for left
           int data = A.front();
           A.erase(A.begin());
           
           // Insert null if there is no element
           if(data == -1){ 
               temp->left = nullptr;
           }
           else{
               Node* n = new Node(data);       // Create a new node and insert ig to left
               temp->left = n;
               q.push(temp->left);                 // Push the left back to queue
           }
           
           
        //   Same for right element of the current node
           data = A.front();
           A.erase(A.begin());
           
           if(data == -1){
               temp->right = nullptr;
           }
           else{
               Node* n = new Node(data);
               temp->right = n;
               q.push(temp->right);
           }
       }
       return root;
    }

```